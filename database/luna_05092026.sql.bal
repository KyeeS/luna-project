-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: May 09, 2026 at 01:49 AM
-- Server version: 5.7.39
-- PHP Version: 8.3.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `luna`
--

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `ID` int(11) NOT NULL,
  `Username` varchar(32) NOT NULL,
  `Name` varchar(32) NOT NULL,
  `Level` smallint(6) NOT NULL DEFAULT '1',
  `LevelPoint` mediumint(9) NOT NULL DEFAULT '0',
  `Cash` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `BankMoney` int(11) UNSIGNED NOT NULL DEFAULT '0',
  `Skin` smallint(5) UNSIGNED NOT NULL DEFAULT '1',
  `PX` float NOT NULL DEFAULT '0',
  `PY` float NOT NULL DEFAULT '0',
  `PZ` float NOT NULL DEFAULT '0',
  `PA` float NOT NULL DEFAULT '0',
  `RegisterAt` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `LastLogin` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `TimePlayed` int(11) NOT NULL DEFAULT '0',
  `Sex` tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
  `BirthDay` tinyint(3) UNSIGNED NOT NULL,
  `BirthMonth` tinyint(3) UNSIGNED NOT NULL,
  `BirthYear` smallint(5) UNSIGNED NOT NULL,
  `Hunger` float NOT NULL,
  `Thirsty` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `ucp`
--

CREATE TABLE `ucp` (
  `#` int(11) NOT NULL,
  `Username` varchar(32) NOT NULL,
  `Password` varchar(84) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `ucp`
--
ALTER TABLE `ucp`
  ADD PRIMARY KEY (`#`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `ucp`
--
ALTER TABLE `ucp`
  MODIFY `#` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
