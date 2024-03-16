CREATE TABLE IF NOT EXISTS `ESP_LED` (
 `id` int(11) NOT NULL AUTO_INCREMENT,
 `MAC` varchar(50) NOT NULL,
 `IP` varchar(50) NOT NULL,
 `status` varchar(50) NOT NULL DEFAULT '0',
 PRIMARY KEY (`id`)
);
