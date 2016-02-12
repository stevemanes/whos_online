<?php
// $Id:$

/**
 * @file  whos_online_list.tpl.php
 * @see template_preprocess()
 */
//print debug($variables, 'whos_online_list.tpl.php');

$out = $variables['items']['#data'];
?>
<!-- Registered users -->
<div id="users_header"><?php print $out['registered']['header'] ?></div>
<div id="users_body">
    <div class="item-list">
    <ul>
        <?php foreach ($out['registered']['users']['items'] as $luser) : ?>
        <li><?php print $luser ?></li>
        <?php endforeach; ?>
    </ul>
    </div>
</div>

<!-- Guest users -->
<div id="guests_header"><?php print $out['guests']['header'] ?></div>
<div id="guests_body">
    <div class="item-list">
    <ul>
        <?php foreach ($out['guests']['users']['items'] as $luser) : ?>
        <li><?php print $luser ?></li>
        <?php endforeach; ?>
    </ul>
    </div>
</div>

<!-- Bots -->
<div id="bots_header"><?php print $out['bots']['header'] ?></div>
<div id="bots_body">
    <div class="item-list">
    <ul>
        <?php foreach ($out['bots']['users']['items'] as $luser) : ?>
        <li><?php print $luser ?></li>
        <?php endforeach; ?>
    </ul>
    </div>
</div>
