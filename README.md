# OPencvHW01
作業1 : opencv 與AVX

把一張影像做灰階化後做threasholding，門檻值為128，大於128為255，小於或等於128為0。

接著做morphology裡面的open和close，各做100次，kernel要為3*3到9*9之間，紀錄做open和close的執行速度。

比對以下項目的差別：

1.沒有使用AVX

2.使用AVX

3.查multi thread(map & reduce)加速

