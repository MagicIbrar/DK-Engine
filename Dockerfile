FROM node:24-bookworm-slim
WORKDIR /app
COPY package.json package-lock.json ./
RUN npm ci --omit=dev --ignore-scripts
COPY index.html join.html launch.html server.mjs THIRD_PARTY_NOTICES.md ./
COPY src ./src
COPY server ./server
COPY site ./site
COPY web/public ./web/public
COPY tools ./tools
COPY vendor ./vendor
COPY client-assets ./client-assets
COPY deploy ./deploy
ENV NODE_ENV=production DEKARON_HOST=0.0.0.0 DEKARON_LOCAL_DEMO=0 DEKARON_SERVER_MODE=friends DEKARON_FRIENDS_GATE=1 DEKARON_SECURE_COOKIES=1 PORT=7778
EXPOSE 7778
CMD ["node", "deploy/start-host.mjs"]
