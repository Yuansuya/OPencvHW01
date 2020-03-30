# OPencvHW01
作業1 : opencv 與AVX

把一張影像做灰階化後做threasholding，門檻值為128，大於128為255，小於或等於128為0。

接著做morphology裡面的open和close，各做100次，kernel要為3*3到9*9之間，紀錄做open和close的執行速度。

比對以下項目的差別：

1.沒有使用AVX

2.使用AVX

3.查multi thread(map & reduce)加速

---------------------------------------------------------------------------------------------
kernel      AVX_speed        NON-AVX_spped
3x3         900~1100(ms)     1300~1400(ms)
9x9         2700~2800(ms)    4000~4100(ms)
---------------------------------------------------------------------------------------------
multi thread(map & reduce)加速
multi-threading的缺點:
1. 除錯困難 
  難度會隨著 thread 的增加而變得越來越困難，入門的 IDE 的單步執行幾乎沒什麼用處，你得隨時注意 thread id 的變化，外加用上 debugger 一些進階功能。
2. 效能不如預期
  微軟給用戶的建議是，開啟的 thread 數量最好是：CPU x 2 + 1,因為如果你每個 connection 配給一個 thread，CPU 需要花費大量的時間於 context switch 上
multi-threading的優點:
1. Responsiveness
    響應度高：一個多線程的應用在執行中，即使其中的某個線程堵 塞，其他的線程還可繼續執行，從而提高響應速度
2. Resource Sharing
    資源共享：同一進程的多個線程共享該進程的内存等資源
3. Economy 
    經濟性：創建和切換線程的開銷要低於進程。
4. Scalability
 可擴展性：行程可以採用多處理機結構。
