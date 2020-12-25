# これはなにか

EV3RTの練習です。

各アプリの数字順に、README.mdに書いてあることを学んでいけば
最終的に自力でアプリが書ける状態を目指していきます。

利用環境はV1.0(HRP3カーネル)です。

# EV3RTのインストール

https://dev.toppers.jp/trac_user/ev3pf/wiki/DevEnv

# 本レポジトリのインストール

```
cd hrp3/sdk
git clone https://github.com/ashitani/ev3rt_examples.git
```

# ビルド

hrp3/sdk/ev3rt_examplesに移動して、

```
make app=01_hello
```
などでアプリ(app)が生成されます。

# アプリの転送

sdcard以下のフォルダをFATでフォーマットしたSDカードにコピーします。
このうちuImageはsdk/firmwareで make img=loaderしたものと同じです。

bluetoothでEV3とペアリングします。その後、PAN接続を行います。Macの場合、bluetoothアイコンからMindstromsEV3->ネットワークに接続、などで接続できます。

この状態で、EV3本体で[Load App][Bluetooth PAN]を選択します。
EV3のIPアドレスが10.0.10.1のとき、下記コマンドでアプリを転送できます。

```
make upload ip=10.0.10.1 from=app to=app
```

fromは親機でのファイル名。toはコピー後のファイル名です。toで好きな名前をつけておくと、あとから
[Load App][SD Card]から選択して起動できます。

# 参考リンク

- [EV3RT公式](https://dev.toppers.jp/trac_user/ev3pf/wiki/WhatsEV3RT)
- [EV3RT C API](https://www.toppers.jp/ev3pf/EV3RT_C_API_Reference/index.html)
