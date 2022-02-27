FROM ubuntu:focal
WORKDIR /home/wj
RUN apt-get update;\
	apt-get install -y build-essential libmysqlclient-dev default-libmysqlclient-dev
COPY . .
CMD ["make", "run"]
