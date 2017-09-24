CXX = g++-5
CXXFLAGS = -std=c++14 -Werror=vla
EXEC = sorcery
OBJECTS = MasterSummonerAbility.o activatedAbility.o airelement.o ApprenticeSummonerAbility.o apprsummon.o ascii_graphics.o auraofpower.o Banish.o Blizzard.o board.o bonegolem.o BoneGolemAbility.o card.o darkritual.o deck.o Disenchant.o earthelement.o enchantdec.o enrage.o fireelement.o FireElementalAbility.o giantstrength.o haste.o magicfatigue.o main.o mastersummon.o minion.o novicepyromancer.o NovicePyromancerAbility.o player.o potionseller.o PotionSellerAbility.o prompt.o RaiseDead.o Recharge.o ritual.o silence.o spell.o standstill.o triggeredAbility.o Unsummon.o
DEPENDS = ${OBJECTS.o: .d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
