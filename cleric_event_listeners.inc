Sub CLERIC
    /call SitOn
	/call ClericRoster
	/call CombatTarget
	/if (${combat}==1 && ${Me.SpellReady[Infallible Hammer of Reverence]} && !${Me.Pet.ID}) /call SummonHammer
	/if (!${Me.Buff[Blessing of Reverence].ID}) /call BlessingOfWIll
/return

Sub BlessingOfWIll
  /declare myself string local ${Group.Member[0]}
  /echo ${myself}
  /target Bushman
  /casting "Blessing of Reverence" gem12
  /call FinishCasting
/return

Sub SitOn
  /if (${combat} == 0 && !${Me.Sitting}) /sit on
/return

Sub CombatTarget

  /sqlite c:\macroquest2\partystate.db queue select * from combat;
  /varset combat ${sqlite.result[queue 1 combat]}
  /varset combattarget ${sqlite.result[queue 1 combattarget]}
  /if ( ${sqlite.clear[queue]} ) {
	} else {
	  /echo BOOOOOO
	}
/return

Sub SummonHammer
  /target ${Spawn[${combattarget}]}
  /casting "Infallible Hammer of Reverence" gem6
  /call FinishCasting
/return



Sub ClericRoster
  /declare x int local
  /for x 0 to 5
    /if (${Group.Member[${x}].ID}) {
      /if (${Group.Member[${x}].Dead}) {
	    /target ${Group.Member[${x}]}
	    /casting "Blessing of Resurrection"
		/call FinishCasting
	  } else {
	  
	      /if (${Group.Member[${x}].PctHPs} < 86) {
	        /target ${Group.Member[${x}]}
	        /casting "Reverent Light" gem5
			/call FinishCasting
			/delay 1
          }
	  }
    } else {
	}
  /next x
  /delay 1
/return



#event Pacify "<Phrogeater> pacify #1#"
Sub Event_Pacify(Line, TARGET)
  /target ${Spawn[${TARGET}]}
  /if (${Me.Class.ID} == 2) {
    :PacifyLoop
      /if (${Target.Distance}>190) /keypress w hold
      /if (${Target.Distance}<190) /keypress w 
      /face fast
      /delay 1
    /if (${Target.ID} && ${Target.Distance}>190) /goto :PacifyLoop
    /casting "Soothing Glow" gem11
    /call FinishCasting
  } else {
  }
/return 

#event CombatStart              "<Phrogeater> combat start #1#"
Sub Event_CombatStart (Line, TARGET)
  /varset combat 1
  /varset combattarget ${TARGET}
/return

#event CombatOver               "<Phrogeater> combat over"
Sub Event_CombatOver
  /varset combat 0
  /varset combattarget 0
/return

#event DoTHeal				    "<#*#> dotheal"
Sub Event_DoTHeal
  /if (${Me.Class.ID} == 2) /cast 2
  /call FinishCasting
/return

#event Heal				        "<#*#> heal"
Sub Event_Heal
  /casting "Word of Renewal" gem1
  /call FinishCasting
/return

#event Invite                   "Phrogeater invites you to join a group."
Sub Event_Invite
  /keypress ctrl+i
/return

#event Promise                  "<Phrogeater> promise"
Sub Event_Promise
  /target ${Spawn[${watch}]}
  /delay 1
  /cast 5
  /call FinishCasting
/return

#event ReverseDS                "<Phrogeater> ds #1#"
Sub Event_ReverseDS(Line, TARGET)
  /target ${Spawn[${TARGET}]}
  /cast 3
  /call FinishCasting
/return

#event ShiningArmor	    		"<Phrogeater> Shining Armor"
Sub Event_ShiningArmor
  |/target Phrogeater
  /target ${Spawn[${watch}]}
  /cast 4
  /call FinishCasting
/return

#event WatchTarget	    		"<#1#> watch #2#"
Sub Event_WatchTarget(Line, CALLER, TARGET)
  /echo ${Spawn[${TARGET}]}
  /varset watch ${TARGET}
/return

Sub Buffs
  |/if (${Me.Buff[Summon Corrputed Sokokar].ID} == 0 ) /casting "Bridle of the Corrputed Sokokar" item
/return

Sub Ageo
  /targ ${Spawn[${watch}]}
  /casting "Unified Certitude" gem6 -invis
/return


Sub Watch
  /doevents
  /target ${Spawn[${watch}]}
  /if (${Target.PctHPs} < 85 ) /casting "Reverent Light" gem5
  /call FinishCasting
/return

Sub Buff
  /if (!${Me.Buff[Aura of Loyalty].ID}) /cast 11
/return

Sub Shining(Line, TARGET)
  /target ${TARGET}
  /delay 1
  /cast 4
  /call FinishCasting
/return

Sub GalvosRetort
  |/target Phrogeater
  /target ${Spawn[${watch}]}
  /delay 1
  /if (!${Target.Buff[Galvos' Retort].ID}) {
    /cast 12
	/call FinishCasting
  } else {
  }
  /if (!${Target.Buff[Shining Armor].ID}) {
    /cast 4
	/call FinishCasting
  } else {
  }
/return


Sub Attack
  /face fast
  /target ${Spawn[${combattarget}]}
  /delay 2
  /if (${Target.Body.ID} == 3 && ${Me.SpellReady[Sermon of Rebuke]} && !${Target.Buff[Sermon of Rebuke].ID}) /cast 7
  /call FinishCasting
/return

Sub Med
  :Medititate
    /doevents
    /if ( !${Me.Sitting} ) /sit
  /if ( ${Me.PctMana} < 100 ) /goto :Medititate
/return

Sub FinishCasting
  :casting
    /doevents
  /if (${Me.Casting.ID}) /goto :casting
/return
