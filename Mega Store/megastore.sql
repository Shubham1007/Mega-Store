-- phpMyAdmin SQL Dump
-- version 4.0.4.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 27, 2017 at 09:30 PM
-- Server version: 5.5.32
-- PHP Version: 5.4.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `megastore`
--
CREATE DATABASE IF NOT EXISTS `megastore` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `megastore`;

-- --------------------------------------------------------

--
-- Table structure for table `mcafy`
--

CREATE TABLE IF NOT EXISTS `mcafy` (
  `id` int(3) NOT NULL,
  `name` varchar(30) NOT NULL,
  `phone` varchar(15) NOT NULL,
  `customer_name` varchar(30) NOT NULL,
  `email` varchar(40) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `mcafy`
--

INSERT INTO `mcafy` (`id`, `name`, `phone`, `customer_name`, `email`) VALUES
(99999, 'lplplplp', '11111111', 'uuuiii', 'shubhuuu@gmail,com');

-- --------------------------------------------------------

--
-- Stand-in structure for view `user_information`
--
CREATE TABLE IF NOT EXISTS `user_information` (
`customer_name` varchar(30)
,`email` varchar(40)
,`phone` varchar(15)
);
-- --------------------------------------------------------

--
-- Structure for view `user_information`
--
DROP TABLE IF EXISTS `user_information`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `user_information` AS select `mcafy`.`customer_name` AS `customer_name`,`mcafy`.`email` AS `email`,`mcafy`.`phone` AS `phone` from `mcafy`;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
