<?php
    $mc = new Memcache;
    $mc->connect('127.0.0.1:11211');
    $samplePage = $mc->get('samplePage');

    if($samplePage){
        echo 'Fetching the page from Memcache'; 
        echo '<br>';
        $start_time = microtime(time);
        echo $samplePage;
        $end_time = microtime(time);
        $execution_time = ($end_time - $start_time)*1000000;
        echo '<br>';
        echo '<b>Execution Time:</b> '.$execution_time.' usec';
    
        }else{

        echo 'No page found in Memcache';
        echo '<br>';
        $filename = 'samplePage.php';
        
        $start_time = microtime(time);
        $handle = fopen($filename,'r') or die("Problem in opening file");
        $contents = fread($handle, filesize($filename));
        fclose($handle);
        echo $contents;
        $end_time = microtime(time);
        $execution_time = ($end_time - $start_time)*1000000;

        echo '<br>';
        //execution time of the script
        echo '<b>Execution Time:</b> '.$execution_time.' usec';
        $mc->set('samplePage',$contents, 0, 30);
    }