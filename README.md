# これはなにか

EV3RTアプリ開発者のためのチュートリアルです。各アプリの数字順に、README.mdに書いてあることを学んでいけば最終的に自力でアプリが書ける状態を目指していきます。

開発環境構築が面倒すぎるのでDockerで環境構築できるようにしました。Mac OS上のDocker Desktopで動作確認しています。

# 初期設定

## 開発環境の構築

docker desktopをインストールします。

このレポジトリをcloneします。

```
git clone https://github.com/ashitani/ev3rt_examples.git
```

下記を実行すると、ev3devというコンテナ上に開発環境が設定されます。初回は2-30分はかかるので気長にお待ち下さい。

```
cd ev3rt_examples
docker compose up -d
```

開発環境を終了するときは下記です。

```
docker compose down
```

## EV3の初期設定

コンテナ側のsdcardフォルダはget_sdcard.shでホストにコピーできます。
いったんホストにコピーしたのち、FATでフォーマットしたSDカードにsdcard以下のすべてのフォルダ・ファイルをコピーします。

# ビルド方法（ホストから）

コンテナにいちいちログインするのがかったるいので、ホストからビルドできるスクリプトを添付してあります。

```
./build.sh 01_hello
```

のようにホスト上で実行すればコンテナ上でビルドが走ります。

# アプリの転送（ホストから） [検証中]

bluetoothでEV3とペアリングします。その後、PAN接続を行います。Macの場合、bluetoothアイコンからMindstromsEV3->ネットワークに接続、などで接続できます。

この状態で、EV3本体で[Load App][Bluetooth PAN]を選択します。
EV3のIPアドレスが10.0.10.1のとき、下記コマンドでアプリを転送できます。

```
./upload.sh アプリ名
```

でfrom=app to=アプリ名として転送できるスクリプトを作っておきました。IPアドレスが異なる場合はupload.shを編集しておいてください。

EV3側で[Load App][SD Card]からtoでつけたアプリ名を選択すれば起動できます。

# ホストとEV3との通信

```
./com.sh
```

# 自作アプリを作る

01_helloフォルダをコピーして好きなフォルダ名をつけ、好きに編集しましょう！

# 各種バージョン

EV3RTの開発環境コンテナのバージョン構成は下記です。

- OS: ubuntu 22.04(jimmy)
- GCC-ARM: 6-2017-q1-update
- EV3RT: 1.1

# 参考リンク

- [EV3RT公式](https://dev.toppers.jp/trac_user/ev3pf/wiki/WhatsEV3RT)
- [EV3RT C API](https://www.toppers.jp/ev3pf/EV3RT_C_API_Reference/index.html)
- [EV3RTのubuntu向け設定スクリプト](http://ev3rt-git.github.io/public/ev3rt-prepare-ubuntu.sh)
- [ubuntu20.04以降でのRuby2.7のインストール手順](https://blog.noellabo.jp/entry/2022/05/17/232935)