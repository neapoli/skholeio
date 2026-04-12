<?php

/**
 * @file
 * Theme settings for Skholeio.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function skholeio_form_system_theme_settings_alter(array &$form, FormStateInterface $form_state, ?string $form_id = NULL): void {
  if (isset($form_id)) {
    return;
  }

  $form['custom_styles'] = [
    '#type' => 'details',
    '#title' => t('CSS personalizzato'),
    '#open' => TRUE,
    '#group' => 'bootstrap',
    '#weight' => 100,
  ];

  $form['custom_styles']['custom_css_enabled'] = [
    '#type' => 'checkbox',
    '#title' => t('Abilita CSS personalizzato'),
    '#description' => t('Carica il file <code>css/custom.css</code> del tema Skholeio.'),
    '#default_value' => theme_get_setting('custom_css_enabled'),
  ];
}