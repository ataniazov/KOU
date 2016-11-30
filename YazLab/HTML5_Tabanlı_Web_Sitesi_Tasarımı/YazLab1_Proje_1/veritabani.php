<?php
class Veritabani
{   
    private $host = "localhost";
    private $db_name = "yeniVeri";
    private $username = "test";
    private $password = "test";
    public $conn;
     
    public function VeriBaglanti()
	{
     
	    $this->conn = null;    
        try
		{
            $this->conn = new PDO("mysql:host=" . $this->host . ";dbname=" . $this->db_name, $this->username, $this->password);
            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);	
            
        }
		catch(PDOException $exception)
		{
            echo "Bağlantı başarısız: " . $exception->getMessage();
        }
         
        return $this->conn;
    }
}
?>