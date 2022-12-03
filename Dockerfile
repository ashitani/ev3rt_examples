#-----------------------------------------------------------------------------------------------
# Install Ubuntu 22.04(jammy)
#-----------------------------------------------------------------------------------------------
FROM ubuntu:jammy
RUN apt-get update \
&& apt-get install -y locales\
&& localedef -i en_US -c -f UTF-8 -A /usr/share/locale/locale.alias en_US.UTF-8
ENV LANG en_US.utf8

#-----------------------------------------------------------------------------------------------
# Install dependency apt packages
#-----------------------------------------------------------------------------------------------
RUN apt-get install -y wget bzip2 unzip xz-utils build-essential zlib1g-dev u-boot-tools lib32stdc++6 git curl

#-----------------------------------------------------------------------------------------------
# Install cross compiler (GCC-ARM)
#-----------------------------------------------------------------------------------------------
# Reference: http://ev3rt-git.github.io/public/ev3rt-prepare-ubuntu.sh
ENV GCC_ARM_VER "6-2017-q1-update"
ENV GCC_ARM_URL "https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-linux.tar.bz2"
ENV GCC_ARM_DIR="/opt"
RUN WORK_DIR=`mktemp -d` \
&& cd ${WORK_DIR} \
&& wget "${GCC_ARM_URL}" \
&& tar -xvvf `basename ${GCC_ARM_URL}` -C ${GCC_ARM_DIR} \
&& cd \
&& rm -rf ${WORK_DIR}
ENV PATH=${PATH}:${GCC_ARM_DIR}/gcc-arm-none-eabi-${GCC_ARM_VER}/bin

#-----------------------------------------------------------------------------------------------
# Install EV3RT
#-----------------------------------------------------------------------------------------------
RUN wget http://www.toppers.jp/download.cgi/ev3rt-1.1-release.zip \
&& unzip ev3rt-1.1-release.zip \
&& ln -s ev3rt-1.1-release ev3rt \
&& cd ev3rt \
&& tar Jxfv hrp3.tar.xz \
&& rm hrp3.tar.xz \
&& cd .. && rm ev3rt-1.1-release.zip

#-----------------------------------------------------------------------------------------------
# Install Ruby2.7 (because apt package (3.0) did not work..)
#-----------------------------------------------------------------------------------------------
## Install openssl-1.1
## Reference: https://blog.noellabo.jp/entry/2022/05/17/232935
RUN wget https://www.openssl.org/source/openssl-1.1.1q.tar.gz \
&& tar xf openssl-1.1.1q.tar.gz \
&& cd openssl-1.1.1q/ \
&& ./config --prefix=/opt/openssl-1.1.1 --openssldir=/opt/openssl-1.1.1 shared zlib \
&& make \
&& make install \
&& rmdir /opt/openssl-1.1.1/certs \
&& ln -s /etc/ssl/certs /opt/openssl-1.1.1/certs \
&& cd .. \
&& rm -rf openssl-1.1.1q \
&& rm openssl-1.1.1q.tar.gz

## install ruby-build and build ruby 2.7.7
## reference: https://ja.stackoverflow.com/questions/65536/docker-%E3%81%A7-ruby-rbenv-%E3%81%AE%E3%82%A4%E3%83%B3%E3%82%B9%E3%83%88%E3%83%BC%E3%83%AB%E3%81%8C%E3%81%86%E3%81%BE%E3%81%8F%E3%81%84%E3%81%8B%E3%81%AA%E3%81%84
RUN git clone --depth=1 https://github.com/rbenv/ruby-build && PREFIX=/usr/local ./ruby-build/install.sh && rm -rf ruby-build
RUN ruby-build 2.7.7 /usr/local \
&& gem install shell

#-----------------------------------------------------------------------------------------------
# Clear apt caches
#-----------------------------------------------------------------------------------------------
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
