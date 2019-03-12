let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd /storage/emulated/0/I/KSPatternAnalysis
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +29 /storage/emulated/0/I/KSPatternAnalysis/Extraction.h
badd +30 /storage/emulated/0/I/KSPatternAnalysis/Recorder.h
badd +30 /storage/emulated/0/I/KSPatternAnalysis/LRecorder.h
argglobal
%argdel
$argadd Extraction.h
edit /storage/emulated/0/I/KSPatternAnalysis/Extraction.h
set splitbelow splitright
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
set nosplitbelow
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 1 + 12) / 24)
exe '2resize ' . ((&lines * 19 + 12) / 24)
exe 'vert 2resize ' . ((&columns * 1 + 22) / 44)
exe '3resize ' . ((&lines * 19 + 12) / 24)
exe 'vert 3resize ' . ((&columns * 42 + 22) / 44)
argglobal
enew
file /storage/emulated/0/I/KSPatternAnalysis/-MiniBufExplorer-
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
wincmd w
argglobal
enew
file /storage/emulated/0/I/KSPatternAnalysis/NERD_tree_1
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal nofen
wincmd w
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 80 - ((10 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
80
normal! 014|
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 1 + 12) / 24)
exe '2resize ' . ((&lines * 19 + 12) / 24)
exe 'vert 2resize ' . ((&columns * 1 + 22) / 44)
exe '3resize ' . ((&lines * 19 + 12) / 24)
exe 'vert 3resize ' . ((&columns * 42 + 22) / 44)
tabnext 1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filnxtToO
set winminheight=1 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
