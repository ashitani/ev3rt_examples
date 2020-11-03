# 02_logging

Bluetooth 経由で親機にログを出力します。

## 親機側の設定

pyserial が入っていなければインストール。
```
pip install pyserial
```

下記を実行するとログの出力が画面に表示されます。
```
python -m serial.tools.miniterm /dev/tty.MindstormsEV3-SerialPor 115200
```
Ctrl+]で終了。

なお、ev3rt_examples直下にcom.shというファイルがあるのでそれを実行しても良いです。

## EV3側の設定

SDカードの
ev3rt/etc/rc.conf.ini 
のDebug/DefaultPortをBTに書き換えます。
```
[Debug]
DefaultPort=BT
```
あとはプログラムからsyslog()を呼ぶだけです。

```
syslog(LOG_WARNING, "hello,world");
syslog(LOG_WARNING, "hello,world %d",i);  // printfのようなフォーマットを受け付ける
```

ログレベルはhrp3/include/t_syslog.h に記載があります。
初期設定ではLOG_WARNING以上のレベルでないとリアルタイム表示はされないようです。

```
/*
 *  ログ情報の重要度の定義
 */
#define LOG_EMERG			  UINT_C(0)		/* シャットダウンに値するエラー */
#define LOG_ALERT			  UINT_C(1)
#define LOG_CRIT			  UINT_C(2)
#define LOG_ERROR			  UINT_C(3)		/* システムエラー */
#define LOG_WARNING			  UINT_C(4)		/* 警告メッセージ */
#define LOG_NOTICE			  UINT_C(5)
#define LOG_INFO			  UINT_C(6)
#define LOG_DEBUG			  UINT_C(7)		/* デバッグ用メッセージ */
```

