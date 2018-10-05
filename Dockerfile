FROM edasque/qmk_firmware

RUN apt-get update
RUN apt-get install gcc-arm*
