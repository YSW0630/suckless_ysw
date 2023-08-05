# **🚀 我的suckless設定檔**

## **使用原因**
+ 精簡主義（在不裝補丁下code不超過2000行）
+ 當初選擇archlinux時就是希望不要佔用電腦太多空間，而suckless也符合我的這樣需求。

## **下載方式**
*一些些些有可能會用到的dependencies  :  (archlinux適用)*

字體: FantasqueSansMono Nerd Fonts

some cute programs 👇
> ```alacritty```  
```bemoji```  
```cava```  
```flameshot```  
```light```  
```ranger```  
```nitch```  
```picom```  
```pmixer```  
```noto-fonts```  
```pulsemixer```  
```xautolock```  

``` bash
# command:
git clone https://github.com/YSW0630/suckless_backup
# for dwm
cd suckless_backup/dwm/dwm_alpha
make && sudo make clean install
# the rest of suckless programs also use the command make install
```

## **🐧 dwm展示**
![show_rice](https://github.com/YSW0630/suckless_backup/assets/95664509/87b5630a-972a-46e7-b470-caf4e4e4542e)

## **🐱 slock 展示**
![slock_looks](https://github.com/YSW0630/suckless_backup/assets/95664509/ea73e3e7-4574-49b2-a6c3-e762336df45f)

## **🐢 dmenu 展示**
![dmenu_looks](https://github.com/YSW0630/suckless_backup/assets/95664509/6789c1c0-e8a6-4619-be25-21fd98e248ec)

## **🐬 dwmblocks 展示**
![dwmblocks_looks](https://github.com/YSW0630/suckless_backup/assets/95664509/1c4f934d-6714-44dc-b814-0db293df54cc)

## **🤟 dwm的一些些些手勢**
> super + q : 退出視窗  
super + b : togglebar  
super + enter : 開啟終端機  
super + j : 切換後一個window  
super + k : 切換前一個window  
super + l : master stack 往右推  
super + h : master stack 往左推  
super + sapce : swap master stack  
super + w : 開啟瀏覽器  
super + shift + w : 切換桌布  
super + shift + e : 開啟bemoji  
super + t : 切換為tiling mode  
super + f : 切換為floating mode  
super + m : 切換為maxmium mode  
super + y : 切換 window layout  
super + 1 ~ 5 : 切換tag  
super + n : next tag  
super + p : previous tag  
