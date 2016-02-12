<?php
/* $Id: whos_online_admin.inc 256 2009-01-13 02:51:05Z root $ */

/**
 * @file
 * Who's Online admin form.
 */

function whos_online_admin_settings() {
    $period = drupal_map_assoc(array(300, 600, 900, 1800, 3600, 7200), 'format_interval');

    $form['whos_online_agents_file'] = array(
        '#type'             => 'textfield',
        '#title'            => t('Path to the user agents file.'),
        '#default_value'    => variable_get('whos_online_agents_file', '/web/user-agents/allagents.xml'),
        '#size'             => 100,
        '#maxlength'        => 255,
        '#description'      => t('The absolute path to the user agents master file downloaded from <a href="@file">@file</a>.  For automatic updates, this file and directory needs to be writable by the web server user. You may also add your own agents to addl_agents.txt (see INSTALL.TXT).', array('@file' => url(WHOS_ONLINE_AGENTS_FILE))),
    );
    $form['whos_online_sample_secs'] = array(
        '#type'             => 'select',
        '#title'            => t('Default sample time interval'),
        '#default_value'    => variable_get('whos_online_sample_secs', 900),
        '#options'          => $period,
        '#description'      => t('Configures the number of minutes/hours of inactivity after which a user is no longer considered online.'),
    );
    $form['whos_online_download_frequency'] = array(
        '#type'             => 'select',
        '#title'            => t('Download new user agents master file'),
        '#default_value'    => variable_get('whos_online_download_frequency', 2419200),
        '#options'          =>  array(0         => t('At next cron invocation (NOT recommended!)'),
                                      604800    => t('Every week'),
                                      1209600   => t('Ever two weeks'),
                                      2419200   => t('Every month'),
                                      4838400   => t('Every two months'),
                                      14515200  => t('Every six months')),
        '#description'      => t("Who's Online relies on a master file of user agents which must be downloaded periodically."),
    );
    $form['whos_online_cache_id'] = array(
        '#type'             => 'textfield',
        '#title'            => t('Memcached cache ID'),
        '#default_value'    => variable_get('whos_online_cache_id', 'S0001'),
        '#size'             => 5,
        '#maxlength'        => 5,
        '#description'      => t("If you are running multiple Drupal sites on this web server, give this Drupal instance a unique ID."),
    );
    $form['whos_online_exclude_local_anons'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Show local server hits'),
        '#return_value'     => 1,
        '#default_value'    => variable_get('whos_online_exclude_local_anons', '0'),
        '#description'      => t("Drupal's cron and modules like Aggregator create anonymous sessions to post status mail. This option will filter them out of the Who's Online list."),
    );
    $form['whos_online_show_bots'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Show bots'),
        '#return_value'     => 1,
        '#default_value'    => variable_get('whos_online_show_bots', '0'),
        '#description'      => t("Display known bots. Clicking on a bot will ban it -- good for misbehaving bots chewing up your bandwidth (admin only)."),
    );
    $form['whos_online_use_hostname'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Enable hostname display'),
        '#return_value'     => 1,
        '#default_value'    => variable_get('whos_online_use_hostname', '0'),
        '#description'      => t("This determines how anonymous logins are displayed. If enabled, Who's Online will attempt to determine the user's domain name with a reverse DNS search. Warning: hostname lookups are costly in terms of performance and should be avoided on high traffic sites."),
    );
    $form['whos_online_refresh'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Refresh user agents'),
        '#return_value'     => 1,
        '#default_value'    => 0,
        '#description'      => t("This will refresh the Memcached data from the user agents file and optional add_agents.txt at the next cron invocation."),
    );

    $form['buttons']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration') );
    $form['buttons']['reset'] = array('#type' => 'submit', '#value' => t('Reset to defaults') );

    if (!empty($_POST) && form_get_errors()) {
        drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
    }

    $form['#submit'][] = 'system_settings_form_submit';
    $form['#submit'][] = 'drupal_flush_all_caches';
    $form['#theme'] = 'system_settings_form';

    return $form;
}