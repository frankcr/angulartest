echo 'Remove old site content'
rm -rf /var/www/cetelembe/*
echo 'Copy new site content'
rsync -azv docroot/ /var/www/cetelembe/
echo 'Copy settings file'
cp /var/www/cetelembe/sites/default/default.settings.php /var/www/cetelembe/sites/default/settings.php
cd /var/www/cetelembe
echo 'Update database'
drush updb -y
echo 'Revert features'
drush fra -y
echo 'Clear cache'
drush cc all