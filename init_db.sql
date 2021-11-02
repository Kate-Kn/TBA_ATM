-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema atm
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema atm
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `atm` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci ;
USE `atm` ;

-- -----------------------------------------------------
-- Table `atm`.`company`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`company` (
  `id` INT NOT NULL,
  `title` VARCHAR(45) NOT NULL,
  `description` VARCHAR(500) NOT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`account_type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`account_type` (
  `code` INT NOT NULL,
  `description` VARCHAR(500) NOT NULL,
  PRIMARY KEY (`code`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`currency`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`currency` (
  `name` INT NOT NULL,
  `rate_UAH` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`name`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`account` (
  `iban` VARCHAR(29) NOT NULL,
  `name` VARCHAR(140) NOT NULL,
  `date_open` VARCHAR(12) NOT NULL,
  `balance` DECIMAL(19,4) NOT NULL,
  `company_id` INT NOT NULL,
  `account_type_code` INT NOT NULL,
  `currency_name` INT NOT NULL,
  PRIMARY KEY (`iban`, `company_id`, `account_type_code`, `currency_name`),
  INDEX `fk_account_company_idx` (`company_id` ASC) VISIBLE,
  INDEX `fk_account_account_type1_idx` (`account_type_code` ASC) VISIBLE,
  INDEX `fk_account_currency1_idx` (`currency_name` ASC) VISIBLE,
  CONSTRAINT `fk_account_company`
    FOREIGN KEY (`company_id`)
    REFERENCES `atm`.`company` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_account_account_type1`
    FOREIGN KEY (`account_type_code`)
    REFERENCES `atm`.`account_type` (`code`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_account_currency1`
    FOREIGN KEY (`currency_name`)
    REFERENCES `atm`.`currency` (`name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`user` (
  `passport_num` VARCHAR(29) NOT NULL,
  `name` VARCHAR(100) NOT NULL,
  `surname` VARCHAR(100) NOT NULL,
  `date_of_birth` VARCHAR(12) NOT NULL,
  PRIMARY KEY (`passport_num`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`card`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`card` (
  `card_num` INT(16) NOT NULL,
  `pincode` INT(4) NOT NULL,
  `expire_date` VARCHAR(12) NOT NULL,
  `balance` DECIMAL(19,4) NOT NULL,
  `currency_name` INT NOT NULL,
  `user_passport_num` VARCHAR(29) NOT NULL,
  PRIMARY KEY (`card_num`, `currency_name`, `user_passport_num`),
  INDEX `fk_card_currency1_idx` (`currency_name` ASC) VISIBLE,
  INDEX `fk_card_user1_idx` (`user_passport_num` ASC) VISIBLE,
  CONSTRAINT `fk_card_currency1`
    FOREIGN KEY (`currency_name`)
    REFERENCES `atm`.`currency` (`name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_card_user1`
    FOREIGN KEY (`user_passport_num`)
    REFERENCES `atm`.`user` (`passport_num`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`transaction_card_account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`transaction_card_account` (
  `id` INT NOT NULL,
  `sum` DECIMAL(19,4) NOT NULL,
  `date` VARCHAR(12) NOT NULL,
  `description` VARCHAR(200) NULL,
  `card_card_num` INT(16) NOT NULL,
  `card_currency_name` INT NOT NULL,
  `card_user_passport_num` VARCHAR(29) NOT NULL,
  `account_iban` VARCHAR(29) NOT NULL,
  `account_company_id` INT NOT NULL,
  `account_account_type_code` INT NOT NULL,
  `account_currency_name` INT NOT NULL,
  PRIMARY KEY (`id`, `card_card_num`, `card_currency_name`, `card_user_passport_num`, `account_iban`, `account_company_id`, `account_account_type_code`, `account_currency_name`),
  INDEX `fk_transaction_card_account_card1_idx` (`card_card_num` ASC, `card_currency_name` ASC, `card_user_passport_num` ASC) VISIBLE,
  INDEX `fk_transaction_card_account_account1_idx` (`account_iban` ASC, `account_company_id` ASC, `account_account_type_code` ASC, `account_currency_name` ASC) VISIBLE,
  CONSTRAINT `fk_transaction_card_account_card1`
    FOREIGN KEY (`card_card_num` , `card_currency_name` , `card_user_passport_num`)
    REFERENCES `atm`.`card` (`card_num` , `currency_name` , `user_passport_num`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_transaction_card_account_account1`
    FOREIGN KEY (`account_iban` , `account_company_id` , `account_account_type_code` , `account_currency_name`)
    REFERENCES `atm`.`account` (`iban` , `company_id` , `account_type_code` , `currency_name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`transaction_cash`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`transaction_cash` (
  `id` INT NOT NULL,
  `sum` DECIMAL(19,4) NOT NULL,
  `date` VARCHAR(12) NOT NULL,
  `description` VARCHAR(200) NULL,
  `card_card_num` INT(16) NOT NULL,
  `card_currency_name` INT NOT NULL,
  `card_user_passport_num` VARCHAR(29) NOT NULL,
  PRIMARY KEY (`id`, `card_card_num`, `card_currency_name`, `card_user_passport_num`),
  INDEX `fk_transaction_cash_card1_idx` (`card_card_num` ASC, `card_currency_name` ASC, `card_user_passport_num` ASC) VISIBLE,
  CONSTRAINT `fk_transaction_cash_card1`
    FOREIGN KEY (`card_card_num` , `card_currency_name` , `card_user_passport_num`)
    REFERENCES `atm`.`card` (`card_num` , `currency_name` , `user_passport_num`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `atm`.`transaction_card`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `atm`.`transaction_card` (
  `id` INT NOT NULL,
  `sum` DECIMAL(19,4) NOT NULL,
  `date` VARCHAR(12) NOT NULL,
  `description` VARCHAR(200) NULL,
  `card_card_num` INT(16) NOT NULL,
  `card_currency_name` INT NOT NULL,
  `card_user_passport_num` VARCHAR(29) NOT NULL,
  PRIMARY KEY (`id`, `card_card_num`, `card_currency_name`, `card_user_passport_num`),
  INDEX `fk_transaction_card_card1_idx` (`card_card_num` ASC, `card_currency_name` ASC, `card_user_passport_num` ASC) VISIBLE,
  CONSTRAINT `fk_transaction_card_card1`
    FOREIGN KEY (`card_card_num` , `card_currency_name` , `card_user_passport_num`)
    REFERENCES `atm`.`card` (`card_num` , `currency_name` , `user_passport_num`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
