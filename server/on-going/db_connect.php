<?php
/**
 * A class file to connect to database
 */
class DB_CONNECT {
  //constructor
  function __construct() { 
    $this -> connect();
  }
  //destruct
  function __destruct() {
    $this -> close();
  }
  function connect() {
    $filepath = realpath(dirname(__FILE__));
    require_once($filepath."/dbconfig.php");
    // connect to the mysql phpmyadmin database
    $con = mysqli_connect('DB_SERVER', 'DB_USER', 'DB_PASSWORD') or die(mysql_error());
    
    // select database 
    $db = mysql_select_db('DB_DATABASE') or die(mysql_error());
    
    //returning the curent cursor
    return $con
  }
  /**
   * Function to close db connection
   */
  function close() {
    // closing db connection
    mysqli_close();
  }
}
?>
