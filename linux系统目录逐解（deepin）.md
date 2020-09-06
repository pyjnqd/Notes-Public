#### linux系统目录

lost&found，系统非正常关机则会产生一些文件

etc /etc etc不是什么缩写，来源于法语的du et cetera 翻译成中文就是等等 的意思. 至于为什么在/etc下面存放**配置文件**，按照原始的UNIX的说法 这下面放的都是一堆零零碎碎的东西 这里面放的是系统级的配置文件，用户专属的配置文件在用户自己的home目录下

 **/bin**是系统的一些指令，主要放置一些系统必备的二进制指令。cat、cp、chmod df、dmesg、gzip、kill、ls、mkdir、more、mount、rm、su
  **/sbin** 超级用户指令，一些系统管理的必备程式例如:cfdisk、dhcpcd、dump、e2fsck、fdisk、halt、ifconfig、ifup、 ifdown、init、insmod、lilo、lsmod、mke2fs、modprobe、quotacheck、reboot、rmmod、 runlevel、shutdown
  **/usr/bin**　是你在后期安装的一些软件的运行脚本。主要放置一些应用软体工具的必备执行档例如c++、g++、gcc、chdrv、diff、dig、du、eject、elm、free、gnome*、 gzip、htpasswd、kfm、ktop、last、less、locale、m4、make、man、mcopy、ncftp、 newaliases、nslookup passwd、quota、smb*、wget等。

  **/usr/sbin**  放置一些用户安装的系统管理的必备程式例如:dhcpd、httpd、imap、in.*d、inetd、lpd、named、netconfig、nmbd、samba、sendmail、squid、swap、tcpd、tcpdump等。



/boot 启动时的依赖  GRUB2 LINUX KERNEL均在此目录 启动配置文件在etc目录

/dev linux将设备看做文件，一切皆文件，用一套接口即可访问各种类型的设备；也包含pseudo-device，比如/dev/random用于产生随机数 /dev/null是一个黑洞，任何输入，无输出；dev/zero无限连续不断的空数据流；

/lib bin sbin中所需要的依赖文件、链接文件类似于DLL可以在这里找到；usr/bin所需要的在usr/lib中

/media Temporary mount directory is created for removable devices 

/mnt目录 手动临时挂载文件系统的地方，与dev media的区别，dev是设备文件本身，media时linux系统自动识别的外部设备（可移除），并在media目录下生成对应的文件；mnt时administrator手动挂载，需要使用mount命令，并指定对方的文件系统；即让linux系统知道对方要以什么样的文件系统去读取，以便linux转换为自己的文件系统显示；

 /opt 可选的包 第三方软件可以安装在此，我们自己的软件安装在次目录下面

/proc是运行时内存 CPU 等等各种信息的显示，不占用外存，时刻存于内存中，运行时的各种信息，cpuinfo meninfo 等 还有进程目录 每一个进程对应一个pid标明的目录，随时变化；只是以文件系统的形式提供了查看这些信息的接口；虚拟的目录，是系统内存的映射，我们可以直接访问这个目录来，获取系统信息。

/root  root用户的主目录，并不在/home下

/run目录 Modern Linux distributions include a /run directory as a temporary filesystem (tmpfs) which stores volatile runtime data, following the FHS version 3.0. **According to the FHS version 2.3, such data were stored in /var/run but this was a problem in some cases because this directory isn’t always available at early boot.** As a result, these programs have **had to resort to** **trickery**, such as using /dev/.udev, /dev/.mdadm, /dev/.systemd or /dev/.mount directories, even though the device directory isn’t intended for such data.Among other advantages, this makes the system easier to use normally with the root filesystem mounted read-only.

是一个临时文件系统，存储系统启动以来的信息。当系统重启时，这个目录下的文件应该被删掉或清除。如果你的系统上有 /var/run 目录，应该让它指向 run



/srv  存放服务启动后需要提取的数据（不用服务器就是空）The /srv directory contains “data for services **provided by the system**.” If you were using the Apache HTTP server to serve a website, you’d likely store **your website’s files** in a directory inside the /srv directory.



/sys  该目录下安装了2.6内核中新出现的一个**文件系统 sysfs** 。sysfs文件系统集成了下面3种文件系统的信息：针对进程信息的**proc文件系统**、针对设备的**devfs文件系统**以及针对伪终端的**devpts文件系统**。该文件系统是内核设备树的一个直观反映。当一个内核对象被创建的时候，对应的文件和目录也在内核对象子系统中；sysfs把连接在系统上的设备和总线组织成为一个分级的文件，它们可以由用户空间存取，向用户空间导出内核的数据结构以及它们的属性。



/tmp 存放临时文件的，包括应用的临时文件，重启时会清空，或者是被某些系统软件清空

**/usr**：用户的很多应用程序和文件都放在这个目录下，类似于windows下的program files目录

usr目录下都与用户有关，/usr/src 是**内核源代码**的存放目录

/var  存放经常修改的数据，比如程序运行的日志文件 其实就是/usr的可写部分，因为usr目录是只读的，因此将可写部分独立出来





`/usr`：系统级的目录，可以理解为`C:/Windows/`，`/usr/lib`理解为`C:/Windows/System32`。
`/usr/local`：用户级的程序目录，可以理解为`C:/Progrem Files/`。用户自己编译的软件默认会安装到这个目录下。
`/opt`：用户级的程序目录，可以理解为`D:/Software`，opt有可选的意思，这里可以用于放置第三方大型软件（或游戏），当你不需要时，直接`rm -rf`掉即可。在硬盘容量不够时，也可将/opt单独挂载到其他磁盘上使用。

源码放哪里？
`/usr/src`：系统级的源码目录。
`/usr/local/src`：用户级的源码目录。



deepin将opt usr home lost+found var 挂载到data分区下，data分区专门分一个大的空间，用于平时保存的home 和 opt 以及运行时的 用到的账户相关的usr以及其可写部分var；