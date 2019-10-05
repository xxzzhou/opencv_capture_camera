采集摄像头时，OpenCV imshow()之后没有waitKey()无法实时显示画面。
imshow()之后要加waitKey()才能正确显示。
官方说明如下：
A common mistake for OpenCV newcomers is to call cv::imshow() in a loop through video frames, without following up each draw with cv::waitKey(30). In this case, nothing appears on screen, because highgui is never given time to process the draw requests from cv::imshow().
翻译：opencv新手的一个常见错误是在视频帧中循环调用cv：：imshow（），而不使用cv：：waitkey（30）跟踪每次绘制。在这种情况下，屏幕上不会显示任何内容，因为HighGui从来没有时间处理来自cv：：imShow（）的draw请求。

或者通俗的说：waitkey的作用就是一个延时函数，让界面持续一段时间出现，不然界面出现一下就会消失。

OpenCV windows are only updated when waitKey() is called, and waitKey() only captures input when an OpenCV window has focus. 也就是说，当显示图片时，窗口不用实时更新，所以imshow之前不加waitKey也是可以的，但若显示实时的视频，就必须加waitKey

测试：
waitkey(100)   fps ≈ 600
waitkey（30） fps ≈  60
waitkey  (10)   fps ≈  35~60（浮动很大）
waitkey（5）   fps ≈  36~60

用for循环每10帧算一次fps：
用笔记本电脑摄像头录制好的属性中已显示为30fps的avi视频文件：
如果waitkey(1),视频播放明显比正常速度快，fps显示为64左右。如果waitKey(5)，仍然快，fps为63~64左右。如果waitKey(30)，主观感觉原视频的播放速度变正常，fps为31~32左右。如果waitKey(60)，视频变成慢放，fps为16左右。
（因为没有算法处理视频的程序，fps完全取决于waitkey的参数。当参数为30ms时，和原视频的fps吻合）
捕捉摄像头实时采集的画面：
（晚上测试）waitkey(1)，fps为15左右，画面正常。waitkey(5)，fps仍为15左右，画面正常。waitkey(30)，fps仍未15左右，画面正常。waitkey(60)，fps仍为16左右，画面正常。waitkey(1000)，f'ps为1左右，十分卡。
（白天测试）waitkey(1)，fps为30左右，waitkey(5),fps为30左右，waitkey(30)，fps仍未30左右，画面均正常。waitkey(60),fps变为16左右。
（感觉采集实时摄像头时，只要waitkey的参数设置合理，不要明显太大，fps均可以保持一个稳定值，这个值取决于摄像头本身的帧率，当设置过大时，会卡帧，fps变小）

