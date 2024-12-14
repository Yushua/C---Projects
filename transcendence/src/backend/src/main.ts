import { ValidationPipe } from '@nestjs/common';
import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { config } from 'dotenv';
import * as fs from 'fs';
config();
async function bootstrap() {
  const app = await NestFactory.create(AppModule, {
    httpsOptions: {
      key: fs.readFileSync(`/keys/key.key`),
      cert: fs.readFileSync(`/keys/key.pem`),
    }
  });
  app.useGlobalPipes(new ValidationPipe);
  app.enableCors()
  await app.listen(443);
}
bootstrap();
//network_mode: 10.11.3.20
