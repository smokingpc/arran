# Arran is experimental WDF sound card driver.
Arran is my experimental WDF driver for soundcard.

Target sound card is PCIe soundcard with CMI8738 chip. It is easier to get chip datasheet.

[Development Environment]

VisualStudio 2019 / 2022

WDK 10.0.20348 / WindowsSDK 10.0.20348

<br>
#Arran : 實驗性音效卡Driver
Arran 是寫完NVMe Driver後偶然想玩一下音效卡與DirectSound搭配的實驗性質Driver。

由於MSDN一直沒講清楚Driver層該如何與DirectX搭配，看了很久突發奇想：或許不需要糾結這個，

只要做好Driver的基礎工作，如何整合也許是DirectX函式庫的工作，所以寫了這個Aaran試試看。

目前目標是搭配PCIe 的 CMI8738音效卡（Datasheet資料好找）

作者：SmokingPC , 歡迎來訊討論

[開發環境]

VisualStudio 2019 / 2022

WDK 10.0.20348 / WindowsSDK 10.0.20348
