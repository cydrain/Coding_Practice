# Runtime Error: 18-19, 21-25, 27
class MatchEngine(object):

    #-----------------------------------------------------------------
    def __init__(self):
        self.__buy_list = []
        self.__sell_list = []

    #-----------------------------------------------------------------
    def processOrder(self, o):
        if (o['cmd'] == 'BUY'):
            self.buy(o)
        elif (o['cmd'] == 'SELL'):
            self.sell(o)
        elif (o['cmd'] == 'CANCEL'):
            self.cancel(o)
        elif (o['cmd'] == 'MODIFY'):
            self.modify(o)
        else:
            self.printo(o)

    #-----------------------------------------------------------------
    def trade(self, o1, o2, volume):
        print "TRADE", o1['orderID'], o1['price'], volume, o2['orderID'], o2['price'], volume

    #-----------------------------------------------------------------
    def buy(self, bo):
        i = len(self.__sell_list) - 1
        # check __sell_list from tail to head (price low to high)
        while (bo['volume'] > 0 and i >= 0):
            if (bo['price'] >= self.__sell_list[i]['price']):
                volume = min(bo['volume'], self.__sell_list[i]['volume'])
                self.trade(self.__sell_list[i], bo, volume)
                # if buyOrder has quantity left, continue
                if (bo['volume'] >= self.__sell_list[i]['volume']):
                    bo['volume'] -= self.__sell_list[i]['volume']
                    self.__sell_list.pop(i)
                    continue
                else:
                    self.__sell_list[i]['volume'] -= bo['volume']
                    bo['volume'] = 0
            i = i - 1
        if (bo['volume'] > 0 and bo['type'] != 'IOC'):
            i = 0
            n = len(self.__buy_list)
            # insert bo into __buy_list in descending order
            while (i < n and bo['price'] <= self.__buy_list[i]['price']):
                i = i + 1
            self.__buy_list.insert(i, bo)

    #-----------------------------------------------------------------
    def sell(self, so):
        i = 0
        # check __buy_list from head to tail (price high to low)
        while (so['volume'] > 0 and i < len(self.__buy_list)):
            if (so['price'] <= self.__buy_list[i]['price']):
                volume = min(so['volume'], self.__buy_list[i]['volume'])
                self.trade(self.__buy_list[i], so, volume)
                # if sellOrder has quantity left, continue
                if (so['volume'] >= self.__buy_list[i]['volume']):
                    so['volume'] -= self.__buy_list[i]['volume']
                    self.__buy_list.pop(i)
                    continue
                else:
                    self.__buy_list[i]['volume'] -= so['volume']
                    so['volume'] = 0
            i = i + 1
        if (so['volume'] > 0 and so['type'] != 'IOC'):
            i = 0
            n = len(self.__sell_list)
            # insert so into __sell_list in descending order
            while (i < n and so['price'] < self.__sell_list[i]['price']):
                i = i + 1
            self.__sell_list.insert(i, so)

    #-----------------------------------------------------------------
    def cancel(self, o):
        i = len(self.__buy_list) - 1
        while (i >= 0):
            if (o['orderID'] == self.__buy_list[i]['orderID']):
                self.__buy_list.pop(i)
                return
            i = i - 1

        i = len(self.__sell_list) - 1
        while (i >= 0):
            if (o['orderID'] == self.__sell_list[i]['orderID']):
                self.__sell_list.pop(i)
                return
            i = i - 1

    #-----------------------------------------------------------------
    def modify(self, o):
        found = False
        order = {}
        i = len(self.__buy_list) - 1
        while (found == False and i >= 0):
            if (o['orderID'] == self.__buy_list[i]['orderID']):
                order = self.__buy_list[i]
                self.__buy_list.pop(i)
                found = True
            i = i - 1

        i = len(self.__sell_list) - 1
        while (found == False and i >= 0):
            if (o['orderID'] == self.__sell_list[i]['orderID']):
                order = self.__sell_list[i]
                self.__sell_list.pop(i)
                found = True
            i = i - 1

        order['cmd'] = o['cmd_new']
        order['price'] = o['price']
        order['volume'] = o['volume']
        
        self.processOrder(order)

    #-----------------------------------------------------------------
    def printo(self, o):
        print "SELL:"
        if (len(self.__sell_list) > 0):
            price = 0
            volume = 0
            for order in self.__sell_list:
                if (order['price'] != price):
                    if (price != 0):
                        print price, volume
                    price = order['price']
                    volume = order['volume']
                else:
                    volume += order['volume']
            print price, volume

        print "BUY:"
        if (len(self.__buy_list) > 0):
            price = 0
            volume = 0
            for order in self.__buy_list:
                if (order['price'] != price):
                    if (price != 0):
                        print price, volume
                    price = order['price']
                    volume = order['volume']
                else:
                    volume += order['volume']
            print price, volume

    #-----------------------------------------------------------------
    def run(self):
        while (True):
            line = raw_input()
            order = {}
            words = line.split()
            try:
                if (words[0] == 'BUY' or words[0] == 'SELL'):
                    if (len(words) != 5):
                        continue
                    order['cmd'] = words[0]
                    order['type'] = words[1]
                    order['price'] = int(words[2])
                    order['volume'] = int(words[3])
                    order['orderID'] = words[4]
                    if (order['type'] not in ['IOC', 'GFD']):
                        continue
                    if (order['price'] <= 0 or order['volume'] <= 0):
                        continue
                elif (words[0] == 'CANCEL'):
                    if (len(words) != 2):
                        continue
                    order['cmd'] = words[0]
                    order['orderID'] = words[1]
                elif (words[0] == 'MODIFY'):
                    if (len(words) != 5):
                        continue
                    order['cmd'] = words[0]
                    order['orderID'] = words[1]
                    order['cmd_new'] = words[2]
                    order['price'] = int(words[3])
                    order['volume'] = int(words[4])
                    if (order['cmd_new'] not in ['BUY', 'SELL']):
                        continue
                    if (order['price'] <= 0 or order['volume'] <= 0):
                        continue
                elif (words[0] == 'PRINT'):
                    if (len(words) != 1):
                        continue
                    order['cmd'] = words[0]
                else:
                    continue
                
                self.processOrder(order)
                    
            except Exception as e:
                continue
        
def test():
    me = MatchEngine()
    me.run()

if __name__ == '__main__':
    test()


