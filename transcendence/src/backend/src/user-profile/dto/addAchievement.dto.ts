import { IsNotEmpty } from "class-validator";
import { Column } from "typeorm";

export class AddAchievement {
    @Column()
    @IsNotEmpty()
    nameAchievement: string;
    @IsNotEmpty()
    @Column()
    pictureLink: string;
    @IsNotEmpty()
    @Column()
    message: string;
}
