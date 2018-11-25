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
