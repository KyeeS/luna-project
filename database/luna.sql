-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Apr 30, 2026 at 11:50 AM
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
  `BirthYear` smallint(5) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`ID`, `Username`, `Name`, `Level`, `LevelPoint`, `Cash`, `BankMoney`, `Skin`, `PX`, `PY`, `PZ`, `PA`, `RegisterAt`, `LastLogin`, `TimePlayed`, `Sex`, `BirthDay`, `BirthMonth`, `BirthYear`) VALUES
(1, 'kyomotos', 'Kyomoto_Asano', 2, 299, 0, 0, 193, 1574.81, -2240.57, 13.55, 150.716, '2026-04-11 11:49:30', '2026-04-30 10:58:08', 1777546688, 0, 0, 0, 0),
(2, 'kyomotos', 'John_Fernand', 1, 0, 0, 0, 294, 181.477, -80.356, 1.578, 75.256, '2026-04-11 11:49:30', '2026-04-27 10:04:09', 1777284249, 0, 0, 0, 0),
(3, 'kyomotos', 'John_Doe', 1, 0, 0, 0, 294, -381.175, -1412.49, 25.727, 125.167, '2026-04-13 10:28:58', '2026-04-27 10:11:41', 1777284701, 0, 0, 0, 0),
(4, 'kyomoto', 'Taka_Ao', 1, 0, 0, 0, 294, 0, 0, 0, 0, '2026-04-19 05:14:20', '2026-04-19 05:14:20', 0, 1, 12, 2, 2000),
(6, 'Steinn', 'Memek_Jembut', 0, 0, 0, 0, 201, 135.916, -73.143, 1.43, 218.182, '2026-04-30 11:36:32', '2026-04-30 11:36:45', 1777549005, 1, 10, 2, 2001);

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
-- Dumping data for table `ucp`
--

INSERT INTO `ucp` (`#`, `Username`, `Password`) VALUES
(1, 'kyomoto', '$2b$12$9lGFv52ezstForM7BUUp.ul83ic9ALP6ORwtPLCalc0OkQ4EFi0ma'),
(2, 'kyomotos', '$2b$12$KajSHR1Pe2BNKA9XAsny6.sb/tOYfvr4rUcBJp8rY1KU4cyFuD3Ia'),
(4, 'Steinn', '$2b$12$8nzvmwo42oYxx6Cku97UL.O7EwlIoO311LlxuVWEouI8kLGLyXc/W');

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
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `ucp`
--
ALTER TABLE `ucp`
  MODIFY `#` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
