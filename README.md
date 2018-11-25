在京东买了这个LED阵列板，写了一些代码。

```
sudo apt-get install wiringpi

```
add
```
spicc
spidev
```
to /etc/modules

```
./go smile
```
will compile smile.c and run it

add

```
/home/pi/LED/demo 
```
to /etc/rc.local , will run all demos on boot.

Pictures found at 
树莓派LED阵列 - 张浩斌的文章 - 知乎
https://zhuanlan.zhihu.com/p/50784515

screen数组是初始图像,0表示黑色，1~7对应七种颜色。但是由于电流的限制，一行亮的数值超过一定值就都变成红色了。
一行最多一个白色，一行两个7就会都变成黄色。
