# 04_motor

モータを動かしてみます

## 解説

PORT_A, PORT_BにLARGEモータを接続します。

init()で初期化します。

ev3_motor_steer(EV3_PORT_A,EV3_PORT_B, power, steer);

で左右モータを使って前進と回転が可能です。

powerが-100〜100で全力後進から全力前進までを指定します。
steerが-100〜100で負は左ステアリング、正は右ステアリングです。

進んで左折、を４回繰り返します。
