FROM alpine:3.20.3

EXPOSE 9000

ARG DB_NAME DB_USER DB_PASS DB_HOST
ARG WP_URL WP_TITLE WP_ADMIN_USER WP_ADMIN_PASS WP_ADMIN_EMAIL

RUN apk update && apk upgrade && apk add --no-cache \
      php83 \
      php83-fpm \
      php83-mysqli \
      php83-json \
      php83-curl \
      php83-dom \
      php83-exif \
      php83-fileinfo \
      php83-mbstring \
      php83-openssl \
      php83-xml \
      php83-zip \
      php83-redis \
      php83-phar \
      wget \
      unzip \
      curl && \
    sed -i "s|listen = 127.0.0.1:9000|listen = 9000|g" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|;listen.owner = nobody|listen.owner = nobody|g" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|;listen.group = nobody|listen.group = nobody|g" /etc/php83/php-fpm.d/www.conf && \
    rm -f /var/cache/apk/*

RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
&& chmod +x /usr/local/bin/wp

WORKDIR /var/www/

RUN wget https://wordpress.org/latest.zip && \
	unzip latest.zip && \
	cp -rf wordpress/* . && \
	rm -rf wordpress latest.zip

RUN mkdir -p /home/aconciar/project/srcs/requirements/wordpress/conf
COPY requirements/wordpress/conf/wp-config-create.sh /home/aconciar/project/srcs/requirements/wordpress/conf/wp-config-create.sh
RUN chmod +x /home/aconciar/project/srcs/requirements/wordpress/conf/wp-config-create.sh

ENV DB_NAME=$DB_NAME \
	DB_USER=$DB_USER \
	DB_PASS=$DB_PASS \
	DB_HOST=$DB_HOST \
	WP_URL=$WP_URL \
	WP_TITLE=$WP_TITLE \
	WP_ADMIN_USER=$WP_ADMIN_USER \
	WP_ADMIN_PASS=$WP_ADMIN_PASS \
	WP_ADMIN_EMAIL=$WP_ADMIN_EMAIL

# COPY ./requirements/wordpress/conf/wp-config-create.sh .

# RUN sh wp-config-create.sh && rm wp-config-create.sh && \
# 	chmod -R 0777 wp-content/

ENTRYPOINT ["/home/aconciar/project/srcs/requirements/wordpress/conf/wp-config-create.sh"]
CMD ["/usr/sbin/php-fpm83", "-F"]
