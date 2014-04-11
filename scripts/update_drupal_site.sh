rm -rf /var/www/cetelembe/*
cp -R docroot/ /var/www/cetelembe/
cp /var/www/cetelembe/sites/default/default.settings.php /var/www/cetelembe/sites/default/settings.php
cd /var/www/cetelembe
drush updb -y
drush fra -y
drush cc all