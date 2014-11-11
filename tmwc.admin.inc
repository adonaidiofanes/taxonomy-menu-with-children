<?php

/**
 * @file
 * Admin functions for Taxonomy menu with children module.
 */

/**
 * Admin form for tmwc module.
 * @ingroup forms.
 * @see system_settings_form()
 */
function tmwc_admin_settings() {

	$form['taxonomy_menu_fieldset'] = array(
		'#type' => 'fieldset',
		'#title' => t('Taxonomy menu with children'),
	);

	$taxonomies = taxonomy_get_vocabularies();
	foreach ($taxonomies as $taxonomy) {
		$options[$taxonomy->machine_name] = $taxonomy->name;
	}

	$form['taxonomy_menu_fieldset']['taxonomies'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Select taxonomies to generate block'),
		'#options' => $options,
		//'#required' => TRUE,
		'#description' => t('Select vocabularies which you want to use to generate the blocks'),
		'#default_value' => variable_get('tmwc_taxonomies', array()),
	);

	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Save'),
	);

	return $form;
  
}

function tmwc_admin_settings_submit($form, &$form_state) {

	variable_set('tmwc_taxonomies', $form['taxonomy_menu_fieldset']['taxonomies']['#value']);
	$taxonomyName = $form['taxonomy_menu_fieldset']['taxonomies']['#value'];
	
	$msg = "";
	foreach ($taxonomyName as $value) {
		$vocabulary = taxonomy_vocabulary_machine_name_load($value);
		$msg .= $vocabulary->name . ', ';
	}

	$msg = substr($msg, 0, -2);

	if(!empty($form['taxonomy_menu_fieldset']['taxonomies']['#value'])){
		drupal_set_message('Taxonomy chosen: ' . $msg . ".");
	} else {
		drupal_set_message(t('Settings have been saved!'));
	}

}