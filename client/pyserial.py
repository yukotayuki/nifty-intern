# -*- coding: utf-8 -*-
import serial
import time
import sys

if __name__ == "__main__":
    param = sys.argv
    plen = len(param) # 引数の個数
    print(param)
    print(u"第１引数：" + param[0])
#    print(u"第２引数：" + param[1])

    # t:持続時間
    t = 5;

    # 引数で変更
    if(plen > 1):
        t = param[1];

    ser = serial.Serial('/dev/cu.usbserial-A104X0S1','9600')
    # Arduioの起動待ち(400msぐらいあれば)
    time.sleep(2)
    # 'e'を送る -> ビリビリ
    ser.write(b'e')
    # ビリビリの継続時間
    time.sleep(t)
    ser.close()
