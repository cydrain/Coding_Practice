// UTF-8

设计一个交易引擎，输入为STDIN，输出为STDOUT

支持以下5条命令
1. BUY GFD|IOC price quantity orderId 
2. SELL GFD|IOC price quantity orderID
3. CANCEL orderId
4. MODIFY orderId BUY|SELL price quatity
5. PRINT

* price 和 quantity 都是正整数，orderId 保证唯一
* GFD (Good For Day)
  是指如果指令没有交易成功，或部分交易成功，未交易部分会加入未成交列表
  IOC (Insert Or Cancel)
  是指如果指令没有马上成交，或只有部分成交，未成交部分立刻取消。
* MODIFY 命令可以把 BUY 改为 SELL，或反之
* PRINT 命令按 price 降序打印 SELL 和 BUY 未成交列表，如：
  SELL:
  1100 20
  1000 10
  BUY:
  990 10
  900 8

交易准则1：如果买价大于或等于卖价，立刻发生交易，输出如下打印：
  BUY GFD 1000 10 ORDER1
  SELL GFD 990 8 ORDER2
  TRADE ORDER1 1000 8 ORDER2 990 8
交易准则2：公平原则，价格相同时，先发出的指令先成交
  BUY GFD 1000 10 ORDER1
  BUY GFD 1000 20 ORDER2
  SELL GFD 990 15 ORDER3
  TRADE ORDER1 1000 10 ORDER3 990 10
  TRADE ORDER2 1000 5 ORDER3 990 5
被 MODIFY 的指令相当于 CANCEL 了原指令，并新发了一个指令

