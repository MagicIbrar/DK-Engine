// site/js/auth-pages.js — shared logic for login.html and signup.html.
import { auth, ApiError, currentUserId } from './api.js';
import { phonePresentationRequested, verifiedSession } from '../../web/public/connect.js';

const phone=phonePresentationRequested()||new URLSearchParams(new URLSearchParams(location.search).get('next')?.split('?')[1]||'').get('client')==='phone';
if(phone){
  document.documentElement.classList.add('phone-auth');
  let frame=0;
  const fit=()=>{frame=0;const v=globalThis.visualViewport;document.documentElement.style.setProperty('--phone-height',`${v?.height||innerHeight}px`);document.documentElement.style.setProperty('--phone-top',`${v?.offsetTop||0}px`);
    const input=document.activeElement;if(input?.tagName==='INPUT'){const r=input.getBoundingClientRect(),top=v?.offsetTop||0;if(r.top<top||r.bottom>top+(v?.height||innerHeight))input.scrollIntoView({block:'nearest'});}};
  const schedule=()=>{if(!frame)frame=requestAnimationFrame(fit);};
  globalThis.visualViewport?.addEventListener('resize',schedule);globalThis.visualViewport?.addEventListener('scroll',schedule);globalThis.addEventListener('resize',schedule);document.addEventListener('focusin',schedule);fit();
}

const accountServerAddress = document.getElementById('accountServerAddress');
if (accountServerAddress) {
  accountServerAddress.textContent = location.host;
  fetch('/api/server/info', { cache: 'no-store', credentials: 'same-origin' }).then(r => r.ok ? r.json() : null).then(info => {
    if (info?.name) document.getElementById('accountServerName').textContent = info.name;
  }).catch(() => {});
}
// Preserve the selected game/client destination when switching between signup and login.
for (const link of document.querySelectorAll('.form-foot a')) {
  const target = new URL(link.href, location.href);
  if (target.origin === location.origin && /\/(?:login|signup)\.html$/.test(target.pathname)) {
    target.searchParams.set('next', nextUrl());
    if(new URLSearchParams(location.search).get('credentials')==='1')target.searchParams.set('credentials','1');
    link.href = target.href;
  }
}

function showMsg(msgEl, text, kind) {
  msgEl.textContent = text;
  msgEl.className = `form-msg ${kind}`;
}

function nextUrl() {
  const n = new URLSearchParams(location.search).get('next');
  try {
    const target = new URL(n || (phone?'/?screen=select&client=phone':'account.html'), location.href);
    if (target.origin === location.origin && (target.pathname === '/' || target.pathname.startsWith('/site/'))){
      if(phone)target.searchParams.set('client','phone');
      return target.pathname + target.search + target.hash;
    }
  } catch { /* invalid redirect falls back to the account page */ }
  return 'account.html';
}

let sessionCheckPending=false;
async function redirectIfLoggedIn() {
  if(new URLSearchParams(location.search).get('credentials')==='1')return;
  if(!phone){const id=await currentUserId();if(id)location.href=nextUrl();return;}
  if(sessionCheckPending)return;
  sessionCheckPending=true;
  const submit=document.querySelector('form button[type="submit"]'),msg=document.getElementById('formMsg');
  if(submit)submit.disabled=true;
  let retry=document.getElementById('sessionRetry');
  if(retry)retry.disabled=true;
  try{
    const id=await verifiedSession(location.origin);if(id){location.replace(nextUrl());return;}
    if(submit)submit.disabled=false;if(retry)retry.remove();if(msg)showMsg(msg,'','');
  }catch{
    if(msg)showMsg(msg,'Could not check your account session. Check the connection, then retry.','error');
    if(!retry){retry=document.createElement('button');retry.id='sessionRetry';retry.type='button';retry.className='btn btn-ghost btn-block';retry.textContent='Retry session check';retry.addEventListener('click',()=>void redirectIfLoggedIn());msg?.after(retry);}
  }finally{
    sessionCheckPending=false;
    if(retry?.isConnected)retry.disabled=false;
  }
}

function wireLoginForm() {
  const form = document.getElementById('loginForm');
  if (!form) return;
  const msg = document.getElementById('formMsg');
  const submit = form.querySelector('button[type="submit"]');
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    if(submit.disabled)return;
    const id = form.elements.namedItem('id').value.trim();
    const password = form.elements.namedItem('password').value;
    if (!id || !password) { showMsg(msg, 'Enter an ID and password.', 'error'); return; }
    submit.disabled = true;
    submit.textContent = 'Signing in…';
    form.setAttribute('aria-busy', 'true');
    try {
      const accepted=await auth.login(id, password);
      if(phone&&(typeof accepted?.id!=='string'||!accepted.id))throw new Error('The server did not confirm your account. Retry.');
      showMsg(msg, 'Logged in. Redirecting…', 'ok');
      setTimeout(() => { location.href = nextUrl(); }, 400);
    } catch (err) {
      const text = err instanceof ApiError && err.status === 0
        ? 'Could not reach the account server. Try again shortly.'
        : (err instanceof ApiError ? err.message : 'Login failed.');
      showMsg(msg, text, 'error');
      submit.disabled = false;
      submit.textContent = 'Log In';
      form.setAttribute('aria-busy', 'false');
    }
  });
}

function wireSignupForm() {
  const form = document.getElementById('signupForm');
  if (!form) return;
  const msg = document.getElementById('formMsg');
  const submit = form.querySelector('button[type="submit"]');
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    if(submit.disabled)return;
    const id = form.elements.namedItem('id').value.trim();
    const password = form.elements.namedItem('password').value;
    const confirm = form.elements.namedItem('confirm').value;
    if (!/^[a-zA-Z0-9_-]{3,32}$/.test(id)) { showMsg(msg, 'Use an ID of 3–32 letters, numbers, underscores or dashes.', 'error'); return; }
    if (!password || password.length < 6 || password.length > 128) { showMsg(msg, 'Password must be 6–128 characters.', 'error'); return; }
    if (password !== confirm) { showMsg(msg, 'Passwords do not match.', 'error'); return; }
    submit.disabled = true;
    submit.textContent = 'Creating account…';
    form.setAttribute('aria-busy', 'true');
    try {
      await auth.signup(id, password);
      form.reset();
      showMsg(msg, 'Account created! Opening your account…', 'ok');
      try { await auth.login(id, password); } catch (err) {
        if (!await currentUserId()) throw err;
      }
      setTimeout(() => { location.href = nextUrl(); }, 1800);
    } catch (err) {
      const text = err instanceof ApiError && err.status === 0
        ? 'Could not reach the account server. Try again shortly.'
        : (err instanceof ApiError ? err.message : 'Sign up failed.');
      showMsg(msg, text, 'error');
      submit.disabled = false;
      submit.textContent = 'Sign Up';
      form.setAttribute('aria-busy', 'false');
    }
  });
}

redirectIfLoggedIn();
wireLoginForm();
wireSignupForm();
