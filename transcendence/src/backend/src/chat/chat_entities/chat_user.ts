import { Column, Entity, PrimaryColumn, PrimaryGeneratedColumn } from "typeorm";

@Entity()
export class ChatUser {
	@PrimaryColumn({ unique: true }) ID:               string
	@Column("text", { array: true }) ChatRoomsIn:      string[]
	@Column("text", { array: true }) DirectChatsIn:    string[]
	@Column("text", { array: true }) FriedsWithDirect: string[]
	@Column("text", { array: true }) BlockedUserIDs:   string[]
}
