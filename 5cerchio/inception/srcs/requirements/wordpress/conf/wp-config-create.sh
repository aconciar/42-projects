#!/bin/sh
set -e

echo ">> Inizio script WordPress..."

# Rimuovi vecchio wp-config.php
rm -f /var/www/wp-config.php

# Ricrea il file di configurazione
cat << EOF > /var/www/wp-config.php
<?php
define( 'DB_NAME', '${DB_NAME}' );
define( 'DB_USER', '${DB_USER}' );
define( 'DB_PASSWORD', '${DB_PASS}' );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );
define('FS_METHOD','direct');
\$table_prefix = 'wp_';
define( 'WP_DEBUG', false );
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', __DIR__ . '/' );
}
require_once ABSPATH . 'wp-settings.php';
EOF

# Attendi MariaDB (opzionale ma consigliato)
echo ">> Attendo MariaDB..."
sleep 5

# Controllo se il DB ha le tabelle WordPress
echo ">> Verifico presenza tabelle WordPress..."
if ! mysql -h mariadb -u"${DB_USER}" -p"${DB_PASS}" "${DB_NAME}" -e "SELECT 1 FROM wp_options LIMIT 1;" 2>/dev/null; then
  echo ">> Tabelle mancanti: forzo reinstallazione..."

  wp core install \
    --url="${WP_URL:-https://aconciar.42.fr}" \
    --title="${WP_TITLE:-IlMioBlog}" \
    --admin_user="${WP_ADMIN_USER:-admin}" \
    --admin_password="${WP_ADMIN_PASS:-admin123}" \
    --admin_email="${WP_ADMIN_EMAIL:-admin@admin.com}" \
    --skip-email \
    --allow-root
else
  echo ">> WordPress già installato e funzionante."
fi

exec "$@"