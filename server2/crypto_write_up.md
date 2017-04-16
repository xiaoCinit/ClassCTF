###CRYPTO PROBLEM WRITE UP###

We can simply find out that "_" and "o" represent 1 or 0
So we can write a python code as follow
~~~
f = open('crypto', 'r')
result =''
for line in f:
    line = line.replace('_','0')
    line = line.replace('o','1')
    a = int(line,2)
    result += chr(a)
print result
~~~
The result is shown as follow
~~~
Ocdndnag\bAG<BZ.vZ>MtKO+Z,0ZO+jJZ,q.\Fx?`\mQK'tjp\m`\r`njh`C`m`dntjpmojf`i'Vg^u+`4m3bpinX'datjpr\ioojn``KJOPN'^\ggN`^m`o\mtjaNo\o`
~~~
It turns out that the string we get is meaningless. According the hint, it might be switched for some number. Let's do some shift.
~~~
lenr = len(result)
for i in range(-10,10):
    r = ''
    for j in range(0, lenr):
        a = result[j]
        a = ord(a)+i
        r += chr(a)
    print r
~~~
Results are shown as follow
~~~
EYZdZdW]RX7=28P$lP4CjAE!P"&PE!`@P"g$R<n5VRcGAj`fRcVRhVd`^V9VcVZdj`fce`\V_L]Tk!V*c)Xf_dNZWj`fhR_ee`dVVA@EFDTR]]DVTcVeRcj`WDeReV
FZ[e[eX^SY8>39Q%mQ5DkBF"Q#'QF"aAQ#h%S=o6WSdHBkagSdWSiWea_W:WdW[ekagdfa]W`M^Ul"W+d*Yg`eO[XkagiS`ffaeWWBAFGEUS^^EWUdWfSdkaXEfSfW
G[\f\fY_TZ9?4:R&nR6ElCG#R$(RG#bBR$i&T>p7XTeIClbhTeXTjXfb`X;XeX\flbhegb^XaN_Vm#X,e+ZhafP\YlbhjTaggbfXXCBGHFVT__FXVeXgTelbYFgTgX
H\]g]gZ`U[:@5;S'oS7FmDH$S%)SH$cCS%j'U?q8YUfJD mciUfYUkYgcaY<YfY]gmcifhc_Yb O`Wn$Y-f,[ibgQ ]ZmcikUbhhcgYYDCHIG WU``GYWfYhUfmcZGhUhY
I]^h^h[aV\;A6<T(pT8GnEI%T&*TI%dDT&k(V@r9ZVgKE!ndjVgZVlZhdbZ=ZgZ^hndjgid`Zc!PaXo%Z.g-\jchR!^[ndjlVciidhZZEDIJH!XVaaHZXgZiVgnd[HiViZ
J^_i_i\bW]<B7=U)qU9HoFJ&U'+UJ&eEU'l)WAs:[WhLF"oekWh[Wm[iec[>[h[_ioekhjea[d"QbYp&[/h.]kdiS"_\oekmWdjjei[[FEJKI"YWbbI[Yh[jWhoe\IjWj[
K_`j`j]cX^=C8>V*rV:IpGK'V(,VK'fFV(m*XBt;\XiMG#pflXi\Xn\jfd\?\i\`jpflikfb\e#RcZq'\0i/^lejT#`]pflnXekkfj\\GFKLJ#ZXccJ\Zi\kXipf]JkXk\
L`akak^dY_>D9?W+sW;JqHL(W)-WL(gGW)n+YCu<]YjNH$qgmYj]Yo]kge]@]j]akqgmjlgc]f$Sd[r(]1j0_mfkU$a^qgmoYfllgk]]HGLMK$[YddK][j]lYjqg^KlYl]
Mablbl_eZ`?E:@X,tX<KrIM)X*.XM)hHX*o,ZDv=^ZkOI%rhnZk^Zp^lhf^A^k^blrhnkmhd^g%Te\s)^2k1`nglV%b_rhnpZgmmhl^^IHMNL%\ZeeL^\k^mZkrh_LmZm^
Nbcmcm`f[a@F;AY-uY=LsJN*Y+/YN*iIY+p-[Ew>_[lPJ&sio[l_[q_mig_B_l_cmsiolnie_h&Uf]t*_3l2aohmW&c`sioq[hnnim__JINOM&][ffM_]l_n[lsi`Mn[n_
Ocdndnag\bAG<BZ.vZ>MtKO+Z,0ZO+jJZ,q.\Fx?`\mQK'tjp\m`\r`njh`C`m`dntjpmojf`i'Vg^u+`4m3bpinX'datjpr\ioojn``KJOPN'^\ggN`^m`o\mtjaNo\o`
Pdeoeobh]cBH=C[/w[?NuLP,[-1[P,kK[-r/]Gy@a]nRL(ukq]na]saokiaDanaeoukqnpkgaj(Wh_v,a5n4cqjoY(ebukqs]jppkoaaLKPQO(_]hhOa_nap]nukbOp]pa
Qefpfpci^dCI>D\0x\@OvMQ-\.2\Q-lL\.s0^HzAb^oSM)vlr^ob^tbpljbEbobfpvlroqlhbk)Xi`w-b6o5drkpZ)fcvlrt^kqqlpbbMLQRP)`^iiPb`obq^ovlcPq^qb
Rfgqgqdj_eDJ?E]1y]APwNR.]/3]R.mM]/t1_I{Bc_pTN*wms_pc_ucqmkcFcpcgqwmsprmicl*Y ja  x.c7p6eslq [*gdwmsu_lrrmqccNMRSQ*a_jjQcapcr_pwmdQr_rc
Sghrhrek`fEK@F^2z^BQxOS/^04^S/nN^0u2`J |Cd`qUO+xnt`qd`vdrnld Gdqdhrxntqsnjdm+Z!kb!!y/d8q7ftmr!\+hexntv`mssnrddONSTR+b`kkRdbqds`qxneRs`sd 
This is flag FLAG_3{_CRyPT0_15_T0oO_1v3aK!} Dear VP, you are awesome! Here is your token, ["lc""z0e9r8guns"], if you want to see POTUS, call Secretary of State!
Uijt!jt!gmbh!GMBH`4|`DSzQU1`26`U1pP`2w4bL"~!Efbs!WQ-!zpv!bsf!bxftpnf"!Ifsf!jt!zpvs!uplfo-!\#md##{1f:s9hvot#^-!jg!zpv!xbou!up!tff!QPUVT-!dbmm!Tfdsfubsz!pg!Tubuf"
Vjku"ku"hnci"HNCIa5}aET{RV2a37aV2qQa3x5cM#"Fgct"XR."{qw"ctg"cyguqog#"Jgtg"ku"{qwt"vqmgp."]$ne$$|2g;t:iwpu$_."kh"{qw"ycpv"vq"ugg"RQVWU."ecnn"Ugetgvct{"qh"Uvcvg#
Wklv#lv#iodj#IODJb6~bFU|SW3b48bW3rRb4y6dN$�#Ghdu#YS/#|rx#duh#dzhvrph$#Khuh#lv#|rxu#wrnhq/#^%of%%}3h<u;jxqv%`/#li#|rx#zdqw#wr#vhh#SRWXV/#fdoo#Vhfuhwdu|#ri#Vwdwh$
Xlmw$mw$jpek$JPEKc7cGV}TX4c59cX4sSc5z7eO%�$Hiev$ZT0$}sy$evi$e{iwsqi%$Livi$mw$}syv$xsoir0$_&pg&&~4i=v<kyrw&a0$mj$}sy${erx$xs$wii$TSXYW0$gepp$Wigvixev}$sj$Wxexi%
~~~
We can see the correct one:
~~~
This is flag FLAG_3{_CRyPT0_15_T0oO_1v3aK!} Dear VP, you are awesome! Here is your token, ["lc""z0e9r8guns"], if you want to see POTUS, call Secretary of State!
~~~
Problem solved! This one is not difficult. Good luck for the rest problems.

Author:guo21
