rem Remove old site content
rm -rf /var/www/cetelembe/*
rem Copy new site content
cp -R docroot/ /var/www/cetelembe/
rem Copy settings file
cp /var/www/cetelembe/sites/default/default.settings.php /var/www/cetelembe/sites/default/settings.php
cd /var/www/cetelembe
rem Update database
drush updb -y
rem Revert features
drush fra -y
rem Clear cache
drush cc all