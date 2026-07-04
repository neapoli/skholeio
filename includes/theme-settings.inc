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

  $form['custom_styles']['custom_css_variant'] = [
    '#type' => 'radios',
    '#title' => t('CSS personalizzato da caricare'),
    '#description' => t('Carica un solo foglio di stile personalizzato del tema Skholeio.'),
    '#options' => [
      '0' => t('Default (nessun CSS personalizzato, grafica originale del tema)'),
      '1' => t('CSS personalizzato (<code>css/custom.css</code>)'),
      '2' => t('CSS personalizzato 2 (<code>css/custom2.css</code>)'),
      '3' => t('CSS personalizzato 3 (<code>css/custom3.css</code>)'),
    ],
    // Default a '1' per preservare il comportamento storico (custom.css).
    '#default_value' => theme_get_setting('custom_css_variant') ?? '1',
  ];
}
