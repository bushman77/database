Sub MAGICIAN
	/if (!${Me.Pet.ID}) /casting "Shard of Water" gem10
	/call Buffs
	/call Combat
	/if (${combat} == 0 ) /varset petattack 0
	/call CastQueue
	/if (${combat}==1) /call Attack
	/if (${Me.Buff[Desert Tarantula].ID} == 0 ) /casting "Desert Tarantula Saddle" item
/return

#event SummonPet "<Phrogeater> pet"
Sub Event_SummonPet
  /casting "Shard of Air" gem10
/return

Sub Attack

  /doevents
  /call UpdateTarget
  /call SummonServant
  /call SwarmPets
  /if (${petattack}==0) /call PetAttack
  /call Dot
  /if (${Me.SpellReady[Bolt of Molten Magma]} && ${Me.SpellReady[Twincast]}) /call TwincastNuke
  |/if (${Me.SpellReady[Bolt of Molten Magma]}) /casting "Bolt of Molten Magma"
  /if (${Me.SpellReady[Strike of Many]} && ${Me.PctMana} > 15) /call Nuke
  
/return

Sub SwarmPets
  /if (${Me.AltAbility[Host of the Elements]}) /casting "Host of the Elements|alt"
  /call FinishCasting
/return

Sub SummonServant
  /if (${servantcounter} == 0) /casting "Ruthless Servant" gem11
  /call ServantCounter
  /if (${servantcounter} > 100 ) /varset servantcounter 0
/return

Sub Nuke
  /call UpdateTarget
  /face fast
  /delay 1
  /casting "Strike of Many" gem8
  /call FinishCasting
/return

Sub TwincastNuke
/bc Twincast
  /call UpdateTarget
  /face fast
  /delay 1
  /casting "Twincast" gem9
  /delay 5
  /casting "Bolt of Molten Magma" gem1
  /call FinishCasting
/return



|#event Swarm "<Phrogeater> swarm"
Sub Event_Swarm(Line, TARGET)
  /call UpdateTarget
  /cast 11
  /call FinishCasting
/return

#event Host "<Phrogeater> host"
Sub Event_Host(Line, TARGET)
  /call UpdateTarget
  /if (${Me.SpellReady[Host of the Elements].ID}) {
    /casting "Host of the Elements|alt"
  } else {
    /bc HOSTS not ready
  }
  /call FinishCasting
/return


Sub PetAttack
  /doevents
  /call UpdateTarget
  /delay 1
  /pet attack
  /varset petattack 1
/return

Sub UpdateTarget
  /sqlite c:\macroquest2\partystate.db queue select * from combat;
  /target ${Spawn[${sqlite.result[queue 1 combattarget]}]}
/return

#event DamageShield				"<Phrogeater> Dreamfire coat"
Sub Event_DamageShield
  /target Phrogeater
  /cast 3
  /call FinishCasting
/return

#event Invisibility             "<Phrogeater> invis"
Sub Event_Invisibility
  /aa act Group Perfected Invisibility
/return

#event Invite                   "Phrogeater invites you to join a group."
Sub Event_Invite
  /keypress ctrl+i
/return

Sub Dot
  /if (${Spawn[${combattarget}]} == ${Target.ID}) /echo dot
  /doevents
  /call UpdateTarget
  /delay 1
  |/bc casting wrath of the elements ${Spawn[${combattarget}]}
  /if ( !${Target.Buff[Wrath of the Elements].ID} && ${Target.ID} != ${sk} && !${Target.Dead}) /cast 4
/return

Sub Buffs
  /if (!${Me.Buff[Cognitive Guardian].ID}) /casting "Cognitive Guardian" gem12
  /if (!${Me.PetBuff[Burnout XI]}) {
    /casting "Burnout XI" gem2
  } else {
  }
  /if (!${Me.PetBuff[Velocity]} && !${Me.PetBuff[Spirit of Tala'Tak]}) {
    /casting "Velocity" gem2
  } else {
  }
/return

Sub Med
/echo med
  :Medititate
  /if ( ${Me.PctMana} < 100 ) /goto :Medititate
/return

