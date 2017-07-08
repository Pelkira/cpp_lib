noremap sH <C-w>H
noremap sJ <C-w>J
noremap sK <C-w>K
noremap sL <C-w>L
noremap sh <C-w>h
noremap sj <C-w>j
noremap sk <C-w>k
noremap sl <C-w>l

"filetype plugin indent on

set number
set title
set showmatch
set tabstop=4
set smartindent
set shiftwidth=4
set noexpandtab
syntax on

set ignorecase
set smartcase
set wrapscan

augroup vimrcEx
	au BufRead * if line("'\"") > 0 && line("'\"") <= line("$") |
	\ exe "normal g`\"" | endif
augroup END


set whichwrap=b,s,<,>,[,]

colorscheme darkblue


