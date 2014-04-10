<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Angular Demo'),
  'description' => t('A first ctools panel to include an Angular app.'),
  'category' => t('Angular'),
  'render callback' => 'angular_demo_render',
  'admin info' => 'angular_demo_admin_info',
);

/**
 * 'admin info' callback for panel pane.
 */
function angular_demo_admin_info($subtype, $conf, $contexts) {
  if (!empty($conf)) {
    $block = new stdClass;
    $block->title = isset($conf['override_title']) ? $conf['override_title_text'] : '';
    $block->content = t('A demo panel for a custom ctool content panel');
    return $block;
  }
}


/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function angular_demo_render($subtype, $conf, $panel_args, $context = NULL) {
  $block = new stdClass();

  // initial content is blank
  $block->title = '';

  $block->content = theme('angular_app');

  //Always angular first.

  $component_array = array('bower_components' =>
    array('angular/angular.js',
    'angular-resource/angular-resource.js',
    'angular-route/angular-route.js',
    'angular-bootstrap/ui-bootstrap-tpls.js')
  );

  include_angular_files('cegeka_angular_panel', $component_array);

  return $block;
}

/**
 * @param $module_name
 * @param array $component_array
 */

function include_angular_files($module_name, $component_array = array()) {

  $base_dir = drupal_get_path('module', $module_name);

  // Include all definded components.
  foreach ($component_array as $component_type => $components) {
    foreach ($components as $component) {
      $uri = $base_dir .'/angular/' . $component_type . '/'.$component;
    include_file($uri);
    }
  }

  $app_js = $base_dir .'/angular/app.js';
  include_file($app_js);

  // Include all available views.
  $views = file_scan_directory($base_dir . '/angular/views', '/.*\.js$/');
  foreach ($views as $view) {
    $uri = $view->uri;
    include_file($uri);
  }

  // Include default css files.

  $app_css = $base_dir . '/angular/app.css';
   include_file($app_css, 'css');

  $bootstrap_css = drupal_get_path('module', 'cegeka_angular_panel') . '/angular/bootstrap.3.0.3.min.css';
  include_file($bootstrap_css, 'css');

  // Add basedir as a settings.
  drupal_add_js(array('cegeka_angular_panel' => array('baseUrl' => $base_dir . '/angular/')), 'setting');
}

/**
 * @param $uri
 * @param string $type
 */

function include_file($uri, $type = 'js') {
  if (file_exists($uri)) {
    switch ($type) {
      case 'js':
        drupal_add_js($uri);
        break;
      case 'css':
        drupal_add_css($uri);
        break;
      default:
        $message = t('Incorrect file type: @file_type', array('@file_type' => $type ));
        watchdog('angular', $message);
        drupal_set_message($message, 'error');
        break;
    }
  }
  else {
    $message = t('File not found: @file', array('@file' => $uri ));
    watchdog('angular', $message);
    drupal_set_message($message, 'error');
  }
}