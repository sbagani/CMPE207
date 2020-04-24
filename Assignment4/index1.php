<?php
    $mc = new Memcache;
    $mc->connect('127.0.0.1:11211');
    $mc->set('message', 'Good morning, Have a nice day!', 0, 30);
    echo "Added message to memcache";
    ?>