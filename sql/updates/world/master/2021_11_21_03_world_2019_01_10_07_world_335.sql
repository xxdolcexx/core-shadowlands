-- 
UPDATE `gossip_menu_option` SET `OptionText`="May I have it, please.", `OptionBroadcastTextID`=8548 WHERE `MenuID` IN (85, 141, 381, 410, 411, 436,3984,4502,4512,4513,4540,4541,4542,4561,4562,4575,4576,4577,4658,4659,4676,4690,5061,6650) AND `OptionIndex`=4;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (85,141,381,410,411,436,3984,4502,4512,4513,4540,4541,4542,4561,4562,4575,4576,4577,4658,4659,4676,4690,5061,6650) AND `TextID`=5996;
INSERT INTO `gossip_menu` (`MenuID`,TextID) VALUES (85,5996),(141,5996),(381,5996),(410,5996),(411,5996),(436,5996),(3984,5996),(4502,5996),(4512,5996),(4513,5996),(4540,5996),(4541,5996),(4542,5996),(4561,5996),(4562,5996),(4575,5996),(4576,5996),(4577,5996),(4658,5996),(4659,5996),(4676,5996),(4690,5996),(5061,5996),(6650,5996);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (85, 141, 381, 410, 411, 436,3984,4502,4512,4513,4540,4541,4542,4561,4562,4575,4576,4577,4658,4659,4676,4690,5061,6650) AND `SourceEntry`=5996;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 85, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 85, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 85, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 85, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 85, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 85, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 141, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 141, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 141, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 141, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 141, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 141, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 381, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 381, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 381, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 381, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 381, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 381, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 410, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 410, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 410, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 410, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 410, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 410, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 411, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 411, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 411, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 411, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 411, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 411, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 436, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 436, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 436, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 436, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 436, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 436, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4502, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4502, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4502, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4502, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4502, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4502, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4512, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4512, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4512, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4512, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4512, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4512, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4513, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4513, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4513, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4513, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4513, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4513, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4540, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4540, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4540, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4540, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4540, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4540, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4541, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4541, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4541, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4541, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4541, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4541, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4542, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4542, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4542, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4542, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4542, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4542, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4561, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4561, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4561, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4561, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4561, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4561, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4562, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4562, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4562, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4562, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4562, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4562, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4575, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4575, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4575, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4575, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4575, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4575, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4576, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4576, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4576, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4576, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4576, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4576, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4577, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4577, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4577, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4577, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4577, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4577, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4658, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4658, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4658, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4658, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4658, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4658, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4659, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4659, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4659, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4659, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4659, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4659, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4676, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4676, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4676, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4676, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4676, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4676, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 4690, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 4690, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 4690, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 4690, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 4690, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 4690, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 5061, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 5061, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 5061, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 5061, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 5061, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 5061, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue"),
(14, 6650, 5996, 0, 0, 9, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 taken"),
(14, 6650, 5996, 0, 0, 28, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player does not have quest 6681 complete"),
(14, 6650, 5996, 0, 0, 8, 0, 6681, 0, 0, 1, 0, 0, "", "Show gossip text if player is not rewarded for quest 6681"),
(14, 6650, 5996, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, "", "Show gossip text if player is at least level 24"),
(14, 6650, 5996, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, "", "Show gossip text if player does not have Elegant Letter"),
(14, 6650, 5996, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, "", "Show gossip text if player is a rogue");

UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag` = `npcflag`&~1 WHERE `entry` = 4794;
