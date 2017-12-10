%matplotlib inline
import pandas as pd
import tushare as ts

# 获取数据
data = ts.get_hist_data('510050', '2017-01-01')
data = data.sort_index()

df = pd.DataFrame()
df['close'] = data['close']                         # 收盘价
df['change'] = df['close'] - df['close'].shift(1)   # 当日涨跌

# 计算均线
df['ma5'] = df['close'].rolling(window=5, center=False).mean()      # 5日均线
df['ma20'] = df['close'].rolling(window=20, center=False).mean()    # 20日均线

# 抛弃NA数据
df = df.dropna()

# 计算持仓
df['pos'] = 0
df['pos'][df['ma5']>=df['ma20']] = 10000    # 5日均线高于20日均线，持有多头仓位
df['pos'][df['ma5']<df['ma20']] = -10000    # 5日均线低于20日均线，持有空头仓位
df['pos'] = df['pos'].shift(1).fillna(0)

# 计算每日盈亏和手续费
df['pnl'] = df['change'] * df['pos']    # 盈亏

df['fee'] = 0                           # 手续费
df['fee'][df['pos']!=df['pos'].shift(1)] = df['close'] * 20000 * 0.0003

df['netpnl'] = df['pnl'] - df['fee']    # 净盈亏

# 汇总求和盈亏，绘制资金曲线
df['cumpnl'] = df['netpnl'].sumsum()
df['cumpnl'].plot()

