# 06_multitask


- メインタスクは500msec周期でLCDに0/1を表示します。
- サブタスクは1秒周期でLCDに0/1を表示します。

これを同時に行えるようにしてみます。

## 解説

app.cfgに周期ハンドラを追加します。
周期ハンドラは一定時間おきに実行されます。

```
CRE_TSK(MAIN_TASK, { TA_ACT, 0, main_task, TMIN_APP_TPRI+2, STACK_SIZE, NULL });
CRE_TSK(SUB_TASK, { TA_NULL, 0, sub_task,  TMIN_APP_TPRI+1, STACK_SIZE, NULL });
CRE_CYC(DUB, { TA_STA, { TNFY_ACTTSK, SUB_TASK }, 1000U * 1000U, 0U });
```

2行目がサブタスクの定義で、これは生成時に起動しないタイプのタスクですね。

これを周期的に呼ぶのはCRE_CYCです。

CRE_CYC(周期通知属性, { 通知モード, { 通知モード2, 周期タスク名 }, 起動周期, 起動位相 });

各パラメータの意味は下記です。

| パラメータ | 説明 |
| --- | --- |
|周期通知属性 | 仕様書をみるとTA_STA等のように書くように読めますが、サンプルにDUBとありますのでそれに習います。|
|通知モード | ひとまずTA_ACTとTA_NULLのどちらを書く程度の理解で良さそうです。TA_ACTだと生成時に起動、TA_NULLだと生成時に休止状態|
|通知モード2 | TNFY_ACTTSKと書くらしい。よくわからない |
| 周期タスク名　| 周期的に実行されるタスク名です|
| 起動周期　| マイクロ秒で指定します。|
| 起動位相　| 周期タスクが起動した後に最初にハンドラが呼ばれるまでのディレイ|


## タスク設定

```
CRE_TSK(MAIN_TASK, { TA_ACT, 0, main_task, TMIN_APP_TPRI+2, STACK_SIZE, NULL });
CRE_TSK(SUB_TASK, { TA_NULL, 0, sub_task,  TMIN_APP_TPRI+1, STACK_SIZE, NULL });
CRE_CYC(DUB, { TA_STA, { TNFY_ACTTSK, SUB_TASK }, 1000U * 1000U, 0U });
```

という設定なので、
システム起動時にMAIN_TASKが起動します。
SUB_TASKはTA_NULLなので生成しても起動されませんが、CRE_CYCによって定期的（この間合は1000msec=1秒おきに起動されます。

この場合は周期的に呼ばれるサブタスクのほうが優先度を高くしているので、仮にメインタスクがスリープなしで全力で走っていても
周期タスクのほうが割り込みます。制御系など、常に一定周期で走っていてほしいタスクはこのように設定するといいでしょう。


