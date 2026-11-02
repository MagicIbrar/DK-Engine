#!/usr/bin/env python3
"""Build filtered copies of the A2 server spawn files (share/map/*/mon_*.csv).
Drops every spawn row whose monster index has no row in the 2007 client's
monster.csv (the client crashes on those, see A2-WORLD-CRASH.md).
Writes to ./staged/<map>/<file>; never touches the server folder."""
import glob,os,sys,json
if len(sys.argv)<2: sys.exit('usage: make_staged.py SERVER_DIR [client_monster.csv]')
SERVER=sys.argv[1]
CLIENT_MON=sys.argv[2] if len(sys.argv)>2 else os.path.join(os.path.dirname(os.path.abspath(__file__)),'client_monster.csv')
known={int(l.split(',')[0]) for l in open(CLIENT_MON,encoding='latin1') if l.split(',')[0].strip().isdigit()}
base=os.path.join(SERVER,'share','map'); report={}
for f in sorted(glob.glob(os.path.join(base,'*','mon_*.csv'))):
    raw=open(f,'rb').read(); lines=raw.split(b'\n'); keep=[]; dropped=[]
    for i,l in enumerate(lines):
        p=l.split(b',')[0].strip()
        if p.isdigit() and int(p) not in known: dropped.append((i+1,int(p)))
        else: keep.append(l)
    if dropped and not any(k.strip() for k in keep):
        report[os.path.relpath(f,base)]={'skipped':'every row is server-only content; map is not in the 2007 client, left unchanged','rows_total':len(dropped)}; continue
    if dropped:
        rel=os.path.relpath(f,base); out=os.path.join(os.path.dirname(__file__),'staged',rel)
        os.makedirs(os.path.dirname(out),exist_ok=True); open(out,'wb').write(b'\n'.join(keep))
        ids={}
        for ln,m in dropped: ids.setdefault(m,[]).append(ln)
        report[rel]={'rows_dropped':len(dropped),'rows_total':sum(1 for l in lines if l.strip()),'by_index':{str(k):{'count':len(v),'lines':f'{v[0]}-{v[-1]}'} for k,v in sorted(ids.items())}}
json.dump(report,open(os.path.join(os.path.dirname(__file__),'staged','REPORT.json'),'w'),indent=1)
print(len(report),'files', sum(r.get('rows_dropped',0) for r in report.values()),'rows dropped')
