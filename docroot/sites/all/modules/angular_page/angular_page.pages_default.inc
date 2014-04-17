<?php
/**
 * @file
 * angular_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function angular_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panel_test';
  $page->task = 'page';
  $page->admin_title = 'Panel test';
  $page->admin_description = '';
  $page->path = 'angular';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panel_test_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panel_test';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Angular test';
  $display->uuid = '17616887-7330-47b0-9c2a-00ea50e48f04';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-91b1097b-321c-4393-87f5-dcb8c9b7a8bd';
    $pane->panel = 'middle';
    $pane->type = 'angular_demo_panel';
    $pane->subtype = 'angular_demo_panel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'username' => 'wiifm',
      'tweets_to_show' => 5,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '91b1097b-321c-4393-87f5-dcb8c9b7a8bd';
    $display->content['new-91b1097b-321c-4393-87f5-dcb8c9b7a8bd'] = $pane;
    $display->panels['middle'][0] = 'new-91b1097b-321c-4393-87f5-dcb8c9b7a8bd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panel_test'] = $page;

  return $pages;

}
