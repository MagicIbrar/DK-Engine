// site/js/site.js — shared chrome for every page: header auth state + active-nav highlight.
// Included as <script type="module" src="js/site.js"> after the header markup on every page.
import { auth, currentUserId } from './api.js';
import { frontEndDestination } from '../../src/ui/frontend/return.js';

const skip = document.createElement('a');
skip.className = 'skip-link'; skip.href = '#main-content'; skip.textContent = 'Skip to content';
document.body.prepend(skip);

function el(tag, className, text) {
  const n = document.createElement(tag);
  if (className) n.className = className;
  if (text !== undefined) n.textContent = text;
  return n;
}

async function renderHeaderAuth() {
  const host = document.getElementById('headerAuth');
  if (!host) return;
  host.innerHTML = '';
  const id = await currentUserId();
  if (id) {
    host.append(el('span', 'header-user', `Welcome, ${id}`));
    const account = el('a', 'btn btn-ghost', 'My Account');
    account.href = 'account.html';
    host.append(account);
    const logout = el('button', 'btn btn-ghost', 'Log out');
    logout.addEventListener('click', async () => {
      logout.disabled = true;
      try { await auth.logout(); } catch (err) {
        logout.disabled = false;
        logout.textContent = 'Retry log out';
        logout.title = err.message || 'Could not log out';
        return;
      }
      location.replace(frontEndDestination('login', location).href);
    });
    host.append(logout);
  } else {
    const login = el('a', 'btn btn-ghost', 'Log in');
    login.href = 'login.html';
    const signup = el('a', 'btn btn-gold', 'Sign Up');
    signup.href = 'signup.html?next=%2F';
    host.append(login, signup);
  }
}

function markActiveNav() {
  const here = (location.pathname.split('/').pop() || 'index.html').toLowerCase();
  document.querySelectorAll('.site-nav a').forEach((a) => {
    const href = (a.getAttribute('href') || '').toLowerCase();
    if (href === here || (here.startsWith('forum-') && href === 'forums.html')) {
      a.classList.add('active'); a.setAttribute('aria-current', 'page');
    }
  });
}

renderHeaderAuth();
markActiveNav();
