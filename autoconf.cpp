#include <ios>
#include <stdlib.h>
#include <ncurses.h>
using namespace std;
int y,x,a=1,a1=0;
bool i3wm=false,i3gaps=false,install=true;
void Color(){
if(a==1){
a1=a1+20;
if(a1==800) a=2;
}
if(a==2){
a1=a1-20;
if(a1==0) a=1;
}
init_color(COLOR_BLACK,a1,0,0);
attron(COLOR_PAIR(1));
for(int i=0; i<y*x; i++) printw("#");
}
void Copy(){
system("cp -rf i3 i3blocks i3status neofetch ~/.config/");
system("cp -rf Pictures ~/");
}
void Ubuntuconf(){
printf("####################\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#  i3wm and conf   #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("####################\n");
system("sudo apt install i3wm wicd  compton i3lock feh i3blocks i3status i3bar");
system("sudo apt install xinit arandr");
system("sudo add-apt-repository ppa:elementary-os/daily");
system("sudo apt-get update");
system("sudo apt-get install elementary-desktop");
printf("####################\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#     i3-gaps      #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("####################\n");
if(!i3gaps){
system("mkdir tmp");
system("cd tmp");
system("pwd");
system("sudo apt install libxcb1-dev libxcb-keysyms1-dev libpango1.0-dev libxcb-util0-dev libxcb-icccm4-dev libyajl-dev libstartup-notification0-dev libxcb-randr0-dev libev-dev libxcb-cursor-dev libxcb-xinerama0-dev libxcb-xkb-dev libxkbcommon-dev libxkbcommon-x11-dev autoconf xutils-dev libtool automake make");
system("git clone https://github.com/Airblader/xcb-util-xrm");
system("cd xcb-util-xrm");
system("git submodule update --init");
system("./autogen.sh --prefix=/usr");
system("make");
system("sudo make install");
system("cd ..");
system("cd i3-gaps");
system("git checkout gaps && git pull");
system("autoreconf --force --install");
system("rm -rf build");
system("mkdir build");
system("cd build");
system("../configure --prefix=/usr --sysconfdir=/etc --disable-sanitizers");
system("make");
system("sudo make install");
}
printf("####################\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#      the end     #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("#                  #\n");
printf("####################\n");
}
int main(){
bool gg=false;
int y1=1;
initscr();
noecho();
curs_set(1);
halfdelay(1);
start_color();
init_pair(1,COLOR_BLACK,COLOR_BLACK);
init_pair(2,COLOR_WHITE,COLOR_BLACK);
init_pair(3,COLOR_RED,COLOR_BLACK);
getmaxyx(stdscr,y,x);
while(!gg){
Color();
if(y1==1) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
if(!i3wm) attron(COLOR_PAIR(1));
mvprintw(y/2,x/2,"install i3wm");
if(y1==2) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
if(!i3gaps) attron(COLOR_PAIR(1));
mvprintw(y/2+1,x/2,"install i3gaps");
if(y1==3) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(y/2+2,x/2,"install");
if(y1==4) attron(COLOR_PAIR(1));
else attron(COLOR_PAIR(2));
mvprintw(y/2+3,x/2,"exit");
switch(getch()){
case 410:
getmaxyx(stdscr,y,x);
clear();
break;
case 10:
if(y1==1){
if(!i3wm) i3wm=true;
else i3wm=false;
}
if(y1==2){
if(!i3gaps) i3gaps=true;
else i3gaps=false;
}
if(y1==3) gg=true,install=false;
if(y1==4) gg=true;
break;
case 119:
case 259:
if(y1==0) y1=4;
else y--;
break;
case 115:
case 258:
if(y1==4) y1=1;
else y++;
break;
}
}
endwin();
if(!install){
Ubuntuconf();
Copy();
}
return 0;
}
