DROP TABLE IF EXISTS `mythic_plus_season`;
CREATE TABLE `mythic_plus_season`  (
  `ID` int(10) NOT NULL,
  `SubSeason` int(10) NOT NULL,
  `ExpansionLevel` int(10) NOT NULL,
  `SomeItemLevel` int(10) NOT NULL,
  `VerifiedBuild` int(15) NOT NULL,
  PRIMARY KEY (`ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;

DROP TABLE IF EXISTS `mythic_plus_season_reward_levels`;
CREATE TABLE `mythic_plus_season_reward_levels`  (
  `ID` int(10) NOT NULL,
  `DifficultyLevel` int(10) NOT NULL,
  `WeaklyRewardLevel` int(10) NOT NULL,
  `EndOfRunRewardLevel` int(10) NOT NULL,
  `MythicPlusSeasonID` int(10) NOT NULL,
  `VerifiedBuild` int(15) NOT NULL,
  PRIMARY KEY (`ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;

DROP TABLE IF EXISTS `mythic_plus_season_tracked_affix`;
CREATE TABLE `mythic_plus_season_tracked_affix`  (
  `ID` int(10) NOT NULL,
  `KeystoneAffixID` int(10) NOT NULL,
  `Field_9_1_0_38511_003` int(10) NOT NULL,
  `Field_9_1_0_38511_004` int(10) NOT NULL,
  `DisplaySeasonID` int(10) NOT NULL,
  `VerifiedBuild` int(15) NOT NULL,
  PRIMARY KEY (`ID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

SET FOREIGN_KEY_CHECKS = 1;